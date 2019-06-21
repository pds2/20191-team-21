## Mudanças feitas para a [versão final](https://github.com/pds2/20191-team-21/tree/entrega) do código

### Documentação
A documentação agora está completa e finalizada e pode ser acessada através desse [desse link](https://github.com/pds2/20191-team-21/blob/master/other_arquives/Documenta%C3%A7%C3%A3o%20e-commerce%20(GRUPO%2021).pdf). Além das decisões de implementação que tivemos durante o desenvolvimento do programa e das mudanças que fizemos após a entrevista, acrescentamos também uma breve descrição de cada uma das funções e explicamos através de uma visão geral o funcionamento do programa.

### Fim do _overkill_
Retiramos a herança antes existente na classe Products. Agora ela é uma classe simples, mas que tem um contrato novo que corresponde a todos os tipos de produtos. Os produtos respectivos as antigas subclasses continuam sendo armazenados, no entanto, em arquivos diferentes - isso facilita qualquer busca ou modificação feita nos produtos e retira a herança overkill. Além disso, reestrutura a classe em um formato de container, deixando assim uma solução mais elegante e robusta

### Fim da _godclass_ (bem, o fim da parte "god" - a classe continua de uma nova forma) 
A classe Administrador que antes tinha muitos atributos e métodos (e 1300 linhas!) agora foi reduzida de modo a representar fielmente o contrato anteriormente estabelecido. Ela continua fazendo o que deveria fazer e as funções que não eram de sua responsabilidade foram redistribuidas para que o contrato fosse respeitado

### Terminal de comandos no lugar da navegação por menus
Criamos uma nova classe Terminal que resolve de uma forma mais elegante toda a navegação antes feita pelo terminal que lia inputs de números e usava sequências de _if's_ e _else's_ para decidir sobre o caminho da execução. A usabilidade do programa agora está mais fluida e simples.

### O fim dos _if's_ (ao menos no menu de comando)
Com a classe Terminal, usamos um mapa de comandos que determina o caminho de execução. Seguimos a dica de evitar _if's_ e _switche's_

### Reestruturação das funções de criação e armazenamento dos produtos
Com todas as mudanças, tivemos que reestruturar a criação e armazenamento dos produtos de modo a seguir melhor as novas regras definidas pelo contrato do código
