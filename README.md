# FIAP GLOBAL SOLUTION 2/2024 - GREEN ENERGY
![image](https://github.com/user-attachments/assets/5f82fceb-8800-4643-91f2-90df72616af0)


## Engenharia de Software - 2º SEMESTRE  
### Disciplina:  Edge Computing

#### Integrantes do grupo:
- Alexandre Assis RM: 558927
- Gustavo Ramalho RM: 554582
- Herbert de Sousa RM: 555701

## 💥 Problema: 
O desperdício de energia em residências, especialmente devido ao uso desnecessário de iluminação, é uma realidade comum que impacta tanto as finanças dos consumidores quanto o meio ambiente. Muitas vezes, luzes permanecem acesas em cômodos vazios ou por tempo prolongado, gerando um consumo desnecessário que eleva o valor das contas de energia e contribui para emissões de carbono desnecessárias. Esse problema é agravado pela falta de monitoramento em tempo real e pela ausência de informações claras para os usuários sobre o impacto financeiro e ambiental do uso excessivo de energia elétrica.

Além disso, embora cada vez mais pessoas busquem reduzir seu impacto ambiental, muitos ainda têm dificuldade em adotar hábitos mais sustentáveis dentro de casa, devido à falta de ferramentas que facilitem a conscientização e o monitoramento do consumo. O resultado é um consumo energético ineficiente e insustentável, com um custo alto tanto para os indivíduos quanto para a sociedade em termos de recursos e impacto ambiental.

## 💡 Solução: Controle de Motor via MQTT
Este projeto implementa um sistema de monitoramento de energia integrado com inteligência artificial que vai te ajudar com a redução do gasto de energia diário. Com o Energi+, vamos integrar sensores IoT, inteligência artificial e técnicas de análise de dados para promover o uso consciente de energia. Este sistema oferece monitoramento em tempo real, alertas personalizados e uma interface prática para que os usuários acompanhem seu consumo e ajustem seus hábitos de forma a reduzir o desperdício energético. A solução será implementada em um protótipo de casa inteligente, com componentes controlados por Arduino que será conectado a um servidor MQTT para transferência de dados e ao Node RED para processamento de dados em tempo real.

#### Componentes
- Arduino (ESP32)
- Protoboard
- DHT32
- Luzes LEDs
- MQTT
- Node-RED

#### Bibliotecas
- WiFi
- PubSubClient
- DHT

> [!Observação]
> Nós perguntamos pro professor se a simulação em arduíno poderia ser feita no arduíno físico e foi permitido. Por isso que não há link do wokwi. Toda a simulação do sistema e a integração entre Arduíno, NodeRED e MQTT foi demonstrada ao vivo no vídeo.
