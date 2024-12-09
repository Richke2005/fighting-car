# Arduino Finghting car

O projeto se trata do modelo físico de um carro pequeno de combate. Aplicaremos nosso conhecimento em em mecânica, eletrônica automação e programação. 

Esta iniciativa visa criar um protótipo funcional que possa ser utilizado em diferentes cenários de treinamento e demonstrações.

| :placard: Vitrine.Dev |     |
| -------------  | --- |
| :sparkles: Nome        | **Arduino Finghting car**
| :label: Tecnologias | Arduino, C++
| :fire: Desafio     | TCC Senai Mecatrônica

<!-- Inserir imagem com a #vitrinedev ao final do link -->
![](https://lh3.googleusercontent.com/pw/AP1GczMlGco0VUG7ojkVZcNI1-_jYrxEjoR7Wnh_7M-oiOK86XqVYQ_6KcOWaenyofH_QygA5s9sT1F9eUKa_OC5nwW7glzz8sPJfb-gpHm55YiaaaO8VRqE3bb7LIlTHCCVUE_6fAKlW1e6QEPy_ArTsWNi0w=w820-h615-s-no-gm?authuser=1#vitrinedev)

## Detalhes do projeto
O projeto "Arduino Fighting Car" é uma iniciativa educacional que combina mecânica, eletrônica e programação para criar um carro de combate controlado remotamente. O objetivo é desenvolver um protótipo funcional que possa ser utilizado em competições, treinamentos e demonstrações técnicas.

### Objetivos do Projeto

- **Educação**: Proporcionar uma plataforma prática para o aprendizado de conceitos de mecatrônica.
- **Inovação**: Explorar novas tecnologias e métodos de controle remoto.
- **Competição**: Participar de competições de robótica e mostrar as capacidades do protótipo.

### Estrutura do Carro

O carro é composto por uma estrutura robusta que suporta os componentes eletrônicos e mecânicos. A base é feita de material leve e resistente, garantindo mobilidade e durabilidade durante os combates.

### Funcionalidades

- Controle remoto via Bluetooth
- Luzes LED indicadoras de bateria
- Modo de combate com armas mecânicas

### Componentes Utilizados

- Placa Arduino Uno
- Módulo Bluetooth HC-05
- Motores DC com driver L298N
- LEDs e resistores
- 4 Pilhas 3800mha

### Esquema Elétrico

![Esquema Elétrico](https://lh3.googleusercontent.com/pw/AP1GczPKC67CKtcnqTT6Vrr6oimOBmIKRTD7ApGuUpwN-CWcig-vkCzVYAvB_I6UVzY7bkV1gqRUFm93LY3AtmgLoUjilApclkLbD4_YR8bEMzdPgMMlShBUgNorK5x912uJKquI2yTQKmTEyrhl0DtUrl8MfQ=w665-h477-s-no-gm?authuser=1)

### Sistema de Controle

O controle do carro é realizado via Bluetooth, utilizando um aplicativo móvel que envia comandos para o módulo Bluetooth HC-05 conectado ao Arduino. O Arduino interpreta esses comandos e aciona os motores e outros componentes do carro.

### Desenvolvimento do Software

O software do carro é desenvolvido em C++ utilizando a plataforma do Arduino. O código é responsável por gerenciar a comunicação Bluetooth, controlar os motores, monitorar o estado da bateria e acionar as armas mecânicas.

### Desafios Enfrentados

- **Integração de Componentes**: Garantir que todos os componentes eletrônicos funcionem em harmonia.
- **Estabilidade do Controle**: Desenvolver um sistema de controle responsivo e estável.
- **Autonomia da Bateria**: Otimizar o consumo de energia para prolongar a vida útil da bateria durante as operações.

### Resultados Esperados

Ao final do projeto, espera-se obter um carro de combate totalmente funcional, capaz de ser controlado remotamente e participar de competições. Além disso, o projeto visa proporcionar um aprendizado significativo aos participantes, preparando-os para desafios futuros na área de mecatrônica.

### Como Executar o Projeto

1. Clone o repositório:
    ```sh
    git clone https://github.com/seu-usuario/fighting_car.git
    ```
2. Abra o projeto no PlatformIO.
3. Conecte os componentes conforme o esquema elétrico.
4. Carregue o código na placa Arduino.
5. Utilize um aplicativo de controle Bluetooth para controlar o carro.

### Próximos Passos

- Implementar controle via Wi-Fi
- Adicionar câmera para visão remota
- Criar um aplicativo móvel dedicado

### Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request.

### Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
