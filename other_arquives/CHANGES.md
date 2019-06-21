## Mudanças feitas para a [versão final](https://github.com/pds2/20191-team-21) do código

### Documentação
A documentação agora está completa e finalizada e pode ser acessada através desse [desse link](https://github.com/pds2/20191-team-21/blob/master/other_arquives/Documenta%C3%A7%C3%A3o%20e-commerce%20(GRUPO%2021).pdf). Além das decisões de implementação que tivemos durante o desenvolvimento do programa e das mudanças que fizemos após a entrevista, acrescentamos também uma breve descrição de cada uma das funções e explicamos através de uma visão geral o funcionamento do programa.

### Fim do _overkill_
Retiramos a herança antes existente na classe Products. Agora ela é uma classe simples, mas que tem um contrato novo que corresponde a todos os tipos de produtos. Os produtos respectivos as antigas subclasses continuam sendo armazenados, no entanto, em arquivos diferentes - isso facilita qualquer busca ou modificação feita nos produtos e retira a herança overkill 

###
