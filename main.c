#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

#include "coord.h"
#include "map.h"
#include "sondados.h"
#include "jogador.h"
#include "dominacao.h"

int main()
{
  Map map;
  Sondados sondados;
  Jogadores jogadores;

  Jogador jogador_inicial = {0, 0, 0};
  Jogador *dominado = JOGADOR_NULL;

  int limite_turnos, qtd_sondagem;

  scanf("%d %d %*d %d", &jogador_inicial.coord.x, &jogador_inicial.coord.y, &limite_turnos);

  map_inicializa(&map);
  sondados_inicializa(&sondados, limite_turnos);
  jogadores_inicializa(&map, &jogadores, jogador_inicial, limite_turnos);

  for (int turno = 0; turno < limite_turnos; turno++)
  {
    qtd_sondagem = sondar(&map, &jogadores);
    dominado = dominar(&map, &jogadores, &sondados);
    PRINT("fimturno\n");
    ler_resposta_do_juiz(&map, &jogadores, &sondados, qtd_sondagem, dominado);
  }
  return 0;
}