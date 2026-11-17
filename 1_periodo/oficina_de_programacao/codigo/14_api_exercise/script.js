const listaPedidos = document.getElementById('lista');
const api = 'https://6a06486ec83ba8ad9b3d5ef7.mockapi.io/api/Pizza';
const nome = document.getElementById('nome');
const preco = document.getElementById('preco');

async function mostrarLista() {
    const resposta = await fetch(api);

    const pedidos = await resposta.json();

    renderizar(pedidos);
}

function renderizar(pedidos) {
    lista.innerHTML = '';

    pedidos.forEach(pedido => {
        lista.innerHTML += `
            <div class="card">
                <p>${pedido.id}</p>
                <h3>${pedido.name}</h3>
                <h4>${pedido.price}</h4>
            </div>
        `;
    })
}

async function buscar() {
    const resposta = await fetch(api+'/'+id.value);

    const pedido = await resposta.json();

    lista.innerHTML += `
        <div class="card">
            <p>${pedido.id}</p>
            <h3>${pedido.name}</h3>
            <h4>${pedido.price}</h4>
        </div>
    `;
}

async function criarPedido() {
    await fetch(api, {
        method: "POST",

        headers: {
            "Content-Type": "application/json"
        },

        body: JSON.stringify({
            name: nome.value,
            price: preco.value
        })
    });

    mostrarLista()
}
