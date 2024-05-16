<div align="center">
  <h1>Robô de Ataque com Arduino Uno e Dabble 🤖</h1>
  <h4><em>Projeto desenvolvido para a 1ª RoboTEC da Fatec Jundiaí, consistindo em um robô controlado remotamente via Dabble utilizando Arduino Uno.</em></h4>
</div>
<br>
<h2>Introdução:</h2>
<p align="justify">A Fatec Jundiaí promoveu a participação dos alunos do 3º e 4º semestres do curso de Sistemas Embarcados na 1ª RoboTEC, uma competição de robôs realizada pela instituição. O objetivo do evento é reunir os alunos em equipes para competirem entre si com seus próprios robôs. O desafio proposto consiste na construção de um robô controlado remotamente capaz de transportar um balão de gás e possuir um mecanismo de perfuração para estourar o balão do robô adversário a uma distância máxima de 10 centímetros. O dispositivo deve ser ajustável em altura, podendo ser controlado manual ou automaticamente, e não é permitido o uso de mecanismos de perfuração ejetáveis.</p>
<br>
<h2>Equipe:</h2>
<p><h4>⭢ Gestor:</h4>
Cassiano Ribeiro Bulgarelli.

<h4>⭢ Time de Documentação:</h4>
Maria Lucia da Silva Felicio, Rubens Caetano de Freitas, Vitor Rodrigues Maciel e Wagner Santos.

<h4>⭢ Time de Hardware:</h4>
Adriano Rodrigues Lins Júnior, Alessandro Soares, Diego Cassavara e José Cícero Vilela de Araújo.

<h4>⭢ Time de Software:</h4>
Egner Luiz Porto, Gustavo Tavares Ribeiro, Matheus Ari Ferreira e Vinícius da Silva Oliveira.</p>
<br>
<h2>Nosso Projeto:</h2>
<p align="justify">O projeto oficial do nosso robô foi desenvolvido com base no ESP32. Este repositório representa uma versão mais simplificada e acessível, adaptada para Arduino. Se você deseja acessar o repositório do projeto original feito com ESP32, <a href="https://github.com/Vince-64/Dabble-Controlled-ESP32-Car/tree/master" target="_blank">Clique Aqui!</a>
<br><br>
Em termos de mecânica, o robô foi equipado com quatro rodas, duas fixas nas laterais e duas menores e giratórias posicionadas na frente e atrás, o que proporciona uma movimentação suave e eficiente. Os controles do robô ocorrem através da conexão entre um módulo Bluetooth e o Dabble, uma biblioteca que inclui aplicativo para Android e iOS, o qual simula um gamepad em nossos dispositivos móveis. Essa integração facilita o controle direto do robô pela equipe, utilizando o celular como interface de controle. Para implementar o sistema de ataque, o robô precisou de dois servo motores posicionados na parte superior da estrutura. Esses servo motores foram programados utilizando o FreeRTOS para garantir operação em tempo real. Quanto à energia, o projeto é alimentado por duas baterias 18650 de 3.7V, garantindo a potência necessária para o funcionamento dos componentes.
<br><br>
Aqui estão algumas imagens do robô finalizado:
</p>

<div align="center">
   <img src="https://github.com/matheusari/matheusari/assets/114448911/c3732159-db75-44fa-b789-dadaa771f809">
</div>

<div align="center">
   <img src="https://github.com/matheusari/matheusari/assets/114448911/72440623-4b25-44a5-b836-d4de56161410">
</div>

<div align="center">
   <img src="https://github.com/matheusari/matheusari/assets/114448911/17aa9c67-e304-49a0-a9a0-c416c4b6b809">
</div>
<br>
<p>Veja também o vídeo abaixo, que mostra o funcionamento do projeto:</p>
<div align="center">
   
https://github.com/matheusari/matheusari/assets/114448911/13efaef5-5161-4d5e-aa76-b0c451ca6fcd
  
</div>
