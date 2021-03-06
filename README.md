<p align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Logo_UFMG.png/320px-Logo_UFMG.png" alt="alt text" width="210" height="82">
</p>

# Trabalho Prático PDS II
Projeto final da disciplina de **Programação e Desenvolvimento de Software II (DCC204)** da **UFMG** em 2019/1.
## Tema: e-commerce

| [Introdução](#introdução) | [Motivação](#motivação) | [Integrantes](#integrantes) | [Documentação](#documentação) |[Slides](#slides) | [User Stories](#user-stories) | [Como usar](#como-usar) |  
| ----------- | ------------- | -------------- | -------------- | ----------- | ----------- | ----------- | 

---

### Introdução
Esse trabalho é a consolidação de todo o aprendizado na disciplina de PDSII, ao longo do primeiro semestre de 2019. Conceitos inéditos como modularização, Orientação a Objetos, testes de unidade, refatoração, desenvolvimento em grupo e Github foram implementados ao longo do trabalho de modo a aplicar tudo em um software de médio porte que junta diversas funções em um único ambiente. O resultado disso é um programa funcional, robusto e que engloba muito do que aprendemos ao longo da disciplina.

### Motivação
É evidente o aumento expressivo do número de comércios eletrônicos nos últimos anos. O avanço tecnológico possibilitou a simulação dessa dinâmica no mundo digital e conectou as pessoas a esse ambiente. Foi justamente a importância do comércio eletrônico na vida das pessoas e na economia moderna que nos motivou a buscar entender melhor o que acontece por trás de todo esse processo. Dessa forma, tivemos que pensar como administradores de lojas eletrônicas e como clientes para que pudéssemos criar um programa, ainda que simples, que pudesse englobar toda essa experiência dos usuários (comprador e vendedor).

### Integrantes

- Ágatha Soares (@agathags)
- Eduardo Fiuza (@EduuF)
- Lucas Costa (@slucase)
- Rafael Mendonca (@rfm2018)
- Vitor Mafra (@vitor-mafra)

> Professores: Flávio Figueiredo (@flaviovdf) e Júlio César(@juliosoaresreis)

### Documentação
Clique [aqui](https://github.com/pds2/20191-team-21/blob/master/other_arquives/Documenta%C3%A7%C3%A3o%20e-commerce%20(GRUPO%2021).pdf) para acessar o pdf com a documentação do programa

### Slides
Clique [aqui](https://github.com/pds2/20191-team-21/blob/master/other_arquives/Apresentação%20Trabalho%20Final%20-%20PDSII.pdf) para acessar os slides que usamos para a apresentação

### User Stories

- Como administrador do sistema, quero visualizar, cadastrar, remover e editar produtos na plataforma para que eu possa manter o catálogo da loja atualizado.

- Como administrador do sistema, quero visualizar o histórico das compras realizadas para que eu possa ter controle e acompanhar os lucros da loja.

- Como administrador do sistema, quero visualizar dados dos usuários cadastrados para que eu possa ter controle e acompanhar o crescimento da base de clientes.

- Como administrador do sistema, quero visualizar dados das compras para que eu possa enviar os produtos comprados.

- Como usuário da plataforma, quero criar e editar meu cadastro pessoal, para que possa realizar pedidos na loja.

- Como usuário, quero visualizar o catálogo de produtos, com opções de filtro e ordenação para que eu possa selecionar os desejados com mais facilidade.

- Como usuário, quero ter um carrinho de compras no qual eu possa adicionar e remover produtos, além de visualizar os detalhes (preço, quantidade, etc) de um pedido potencial.

- Como usuário, gostaria de efetivar compras dos produtos selecionados no carrinho, utilizando um cartão cadastrado.

### Como usar
Para logar como administrador, utilize a chave ``alohomora``.

## Lista de comandos para utilização do programa:
Lista de comandos:" << endl << endl

> Mutual commands
- ``help``                     -> Lista comandos de ajuda;

>Admin commands
- ``list products``            -> Lista os produtos em estoque;
- ``create product``           -> Adiciona produto da base de dados;
- ``warehouse remove product`` -> Remove produto da base de dados;
- ``warehouse clear``          -> Limpa a base de dados;
- ``warehouse save``           -> Salva a base de dados em arquivo;

>Admin commands
- ``basket view``              -> Lista produtos na cesta de compras;
- ``basket add product``       -> Adiciona produto a cesta de compras;
- ``basket remove product``    -> Remove produto da cesta de compras;
- ``basket checkout``          -> Finaliza compra;
- ``basket clear``             -> Limpa cesta de compras;