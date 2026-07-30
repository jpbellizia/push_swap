/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:10:26 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 13:10:26 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

	O que é o sort.c
	
	É o despachante: uma função que olha ctx->mode e chama a estratégia correspondente.
	
	c
	void	sort(t_context *ctx)
	
	Por dentro é só uma cadeia de if/else if:
	
	se ctx->mode == mode_simple → chama sort_simple(ctx)
	se mode_medium → sort_medium(ctx)
	se mode_complex → sort_complex(ctx)
	se mode_adaptive → sort_adaptive(ctx)
	
	(Sem switch, que a Norm proíbe.)
	
	Por que existir: o main não deveria conhecer as quatro estratégias. Hoje ele chamaria quatro ifs; com o despachante, ele chama sort(&ctx) e pronto. Se amanhã vocês adicionarem uma quinta estratégia, mexe só no sort.c.
	
	O main fica assim:
	
	c
		define_mode(argc, argv, &ctx);
		sort(&ctx);
		free(...);
	
	Provavelmente também é o lugar do guard de "já está ordenado" — antes de despachar, se is_sorted(&ctx->a), retorna sem fazer nada. Assim nenhuma estratégia precisa repetir essa checagem. Mas isso é opcional; dá pra deixar dentro de cada uma.
	
	Ele é curtinho, umas 12 linhas. E só faz sentido escrever depois que as estratégias existirem — senão você chama funções que não existem e não compila.
	
	Então a ordem é: faz o sort_simple primeiro, testa ele isolado, e o sort.c vem quando tiver pelo menos uma estratégia pronta.
	
	Vamos ao find_min_index dentro do sort_simple.c.
	
 */