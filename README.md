<div align="center" align-items = "center">
	<img alt = "Status do Desafio" title = "Status" src = "https://game.42sp.org.br/static/assets/achievements/so_longm.png">
</div>

<p>Este é meu primeiro jogo 2D, construído com uma biblioteca de interface gráfica personalizada que permite o desenho de janelas e manipulação de eventos.

<div align="center">
<img alt = "Jogo" src = "https://media.giphy.com/media/C7gLPF8v9I08vl6KC3/giphy.gif">
</div>

O jogo é iniciado por um arquivo de mapa no formato ```.ber``` contendo apenas os seguintes caracteres válidos:

- E para _saída_
- P para _jogador_
- C para _colecionáveis_
- 1 para _paredes_
- 0 para _chão_

## Execute o jogo
### Linux e MacOS
Siga as instruções [neste repositório](https://github.com/42Paris/minilibx-linux#readme) para instalar os pacotes necessários para executar o Minilibx

### Janelas
Você precisará instalar o Xserver em sua máquina visto que a biblioteca roda no sistema X-Window. Você também pode usar o WSL no Windows 11 e executar ```wsl --update``` e pronto.

### Clonar repositório e executar
``` c
git clone 
execute ./so_long maps/map1.ber
```
Você pode usar um dos mapas já existentes em ```./maps```, ou você pode até mesmo fazer seu próprio mapa.

