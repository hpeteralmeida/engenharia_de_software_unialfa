1. Liste os clientes cuja quantidade de filhos esteja entre 1 e 3 e cuja renda anual seja maior que R$ 40.000.
    SELECT cliente_nome
    FROM Clientes c
    WHERE (c.qtd_filhos BETWEEN 1 AND 3) AND c.renda_anual > 40000;

2. Liste o nome e sobrenome do cliente, o número do pedido e a receita da venda dos pedidos realizados por clientes cuja Receita_Venda esteja entre R$ 500 e R$ 2.000.
    SELECT c.cliente_nome, c.cliente_sobrenome, p.pedido_numero, p.receita
    FROM Clientes c
    JOIN Pedidos p
    ON p.cliente_id = c.cliente_id 
    WHERE receita_total BETWEEN 500 AND 2000;

3. Crie uma view chamada vw_total_por_loja que apresente o nome da loja e o total de receita gerada por ela.
    CREATE VIEW vw_total_por_loja AS
        SELECT l.nome_loja, SUM(p.receita) AS receita_total
        FROM Lojas l
        JOIN Pedidos p
        ON p.id_loja = l.id_loja
        GROUP BY l.nome_loja;n