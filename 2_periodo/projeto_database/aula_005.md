PROVA PROCESSUAL - 18/09/2026

1. Faturamento total por loja

Utilizando as tabelas lojas e pedidos, apresente o nome da loja e o valor total das vendas realizadas por ela.
Considere somente os pedidos cuja receita da venda seja maior que R$ 500 e cuja quantidade vendida seja igual a 1 unidade.
Agrupe os resultados somente pelo nome da loja, ordene do maior faturamento para o menor e apresente apenas as 5 primeiras lojas.

    SELECT lojas.loja,
        SUM(pedidos.receita_venda)
    FROM lojas
    JOIN pedidos
        ON lojas.id_loja = pedidos.id_loja
    WHERE pedidos.receita_venda > 500
    AND pedidos.qtd_vendida = 1
    GROUP BY lojas.loja
    ORDER BY SUM(pedidos.receita_venda) DESC
    LIMIT 5;

2. Quantidade vendida por produto

Utilizando as tabelas produtos e pedidos, apresente todos os produtos cadastrados, 
inclusive aqueles que ainda não possuem vendas registradas. Mostre o nome do produto 
e a soma da quantidade vendida. Agrupe os resultados somente pelo nome do produto e 
ordene da maior quantidade vendida para a menor. Importante: o resultado deve apresentar 
também os produtos que não possuem nenhuma venda.

    SELECT produtos.nome_produto,
        SUM(pedidos.qtd_vendida)
    FROM produtos
    LEFT JOIN pedidos
        ON produtos.id_produto = pedidos.id_produto
    GROUP BY produtos.nome_produto
    ORDER BY SUM(pedidos.qtd_vendida) DESC;

3. Média de vendas por categoria

Utilizando as tabelas categorias, produtos e pedidos, apresente o nome da categoria 
e a média da receita das vendas dos produtos daquela categoria. Considere somente as 
categorias Monitor ou Notebook. Agrupe os resultados somente pelo nome da categoria e 
ordene da maior média de vendas para a menor.

    SELECT categorias.categoria,
        AVG(pedidos.receita_venda)
    FROM pedidos
    JOIN produtos
        ON pedidos.id_produto = produtos.id_produto
    JOIN categorias
        ON produtos.id_categoria = categorias.id_categoria
    WHERE categorias.categoria = 'Monitor'
    OR categorias.categoria = 'Notebook'
    GROUP BY categorias.categoria
    ORDER BY AVG(pedidos.receita_venda) DESC;

4. Total comprado por cliente

Utilizando as tabelas clientes e pedidos, apresente o nome do cliente e o valor 
total das compras realizadas por ele. Considere somente clientes que tenham renda 
anual maior que R$ 60.000 e tenham 2 ou mais filhos, ou clientes cuja renda anual seja 
maior que R$ 100.000.Agrupe os resultados somente pelo nome do cliente, ordene do maior 
valor comprado para o menor e apresente somente os 10 primeiros resultados.

    SELECT clientes.nome,
        SUM(pedidos.receita_venda)
    FROM clientes
    JOIN pedidos
        ON clientes.id_cliente = pedidos.id_cliente
    WHERE clientes.renda_anual > '100000'
    OR (clientes.renda_anual > '60000'
        AND clientes.qtd_filhos >= '2')
    GROUP BY clientes.nome
    ORDER BY SUM(pedidos.receita_venda) DESC
    LIMIT 10;