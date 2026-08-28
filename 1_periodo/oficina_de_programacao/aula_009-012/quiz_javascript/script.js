const startScreen = document.getElementById("start-screen");
const quizScreen = document.getElementById("quiz-screen");
const resultScreen = document.getElementById("result-screen");


const questionText = document.getElementById("question-text");


const totalQuestionSpan = document.getElementById("total-questions");
const currentQuestionSpan = document.getElementById("current-question");
const answerContainer = document.getElementById("answers-container");
const scoreSpan = document.getElementById("score");
const maxScoreSpan = document.getElementById("max-score");


const startButton = document.getElementById("start-btn");
const skipButton = document.getElementById("skip-quiz-btn");
const restartButton = document.getElementById("restart-btn");
const beginningButton = document.getElementById("beginning-btn");


const quizQuestions = [
    {
        question: "Qual é a capital da frança?",
        answers: [
            { text: "Paris", correct: true},
            { text: "Londres", correct: false},
            { text: "Goiania", correct: false},
            { text: "jata ai", correct: false},
        ],
    },
    {
        question: "Qual a idade do doutor homem ovo",
        answers: [
            { text: "20 anos", correct: false},
            { text: "30 anos", correct: false},
            { text: "sim", correct: true},
            { text: "sei naum", correct: false},
        ],
    },
    {
        question: "Pq o jauzin foi pra escola?",
        answers: [
            { text: "conselho tutelar", correct: false},
            { text: "muié", correct: false},
            { text: "pq hj tem aula", correct: false},
            { text: "pq ele gosta de aprender", correct: true},
        ],
    },
    {
        question: "Pergunta 4",
        answers: [
            { text: "resposta 1", correct: false},
            { text: "resposta 2", correct: false},
            { text: "resposta 3", correct: false},
            { text: "resposta 4", correct: true},
        ],
    },
    {
        question: "Insira a pergunta aqui",
        answers: [
            { text: "45", correct: false},
            { text: "100,2", correct: false},
            { text: "Possivelmente 42", correct: false},
            { text: "Resposta correta", correct: true},
        ]
    },
];

// VARIAVEIS DE ESTADO
let currentQuestionIndex = 0;
let score = 0;
let answerDisabled = false;

totalQuestionSpan.textContent = quizQuestions.length;
maxScoreSpan.textContent = quizQuestions.length;


startButton.addEventListener("click", startQuiz);
skipButton.addEventListener("click", skipQuiz);
restartButton.addEventListener("click", restartQuiz);
beginningButton.addEventListener("click", backToStart);

function startQuiz() {
    currentQuestionIndex = 0;
    score = 0;
    scoreSpan.textContent = "0";

    startScreen.classList.remove("active");
    quizScreen.classList.add("active");

    showQuestion();
}

function showQuestion() {
    answerDisabled = false;

    const currentQuestion = quizQuestions[currentQuestionIndex];
    currentQuestionSpan.textContent = currentQuestionIndex + 1;

    //BARRA DE PROGRESSO

    questionText.textContent = currentQuestion.question;

    answerContainer.innerHTML = "";

    currentQuestion.answers.forEach((answers) => {
        const button = document.createElement("button");
        button.textContent = answers.text;
        button.classList.add("answer-btn");

        button.dataset.correct = answers.correct;

        button.addEventListener("click", selectAnswer);

        answerContainer.appendChild(button);
    })
}

function selectAnswer(event) {
    if (answerDisabled) return;

    answerDisabled = true;

    const selectedButton = event.target;
    const isCorrect = selectedButton.dataset.correct === "true";

    Array.from(answerContainer.children).forEach((button) => {
        if (button.dataset.correct === "true") {
            button.classList.add("correct");
        } else if (button === selectedButton) {
            button.classList.add("incorrect");
        }
    })

    if (isCorrect) {
        score++;
        scoreSpan.textContent = score;
    }

    setTimeout(() => {
        currentQuestionIndex++;

        if (currentQuestionIndex < quizQuestions.length) {
            showQuestion();
        } else {
            showResults();
        }
    }, 1000);
}

function showResults() {
    //FAZ ISSO AQUI OH <-
}

function skipQuiz() {
    quizScreen.classList.remove("active");
    resultScreen.classList.add("active");
}

function restartQuiz() {
    resultScreen.classList.remove("active");
    startQuiz();
}

function backToStart() {
    resultScreen.classList.remove("active");
    startScreen.classList.add("active");
}