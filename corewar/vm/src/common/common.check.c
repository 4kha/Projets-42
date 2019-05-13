/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:33:46 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/27 20:47:04 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_constants(void)
{
	if ((DUMP_SIZE != 32 && DUMP_SIZE != 64)
	|| CYCLES_TO_DIE != 1536
	|| CYCLE_DELTA != 50
	|| NBR_LIVE != 21
	|| MAX_CHECKS != 10
	|| MEM_SIZE != (4 * 1024)
	|| MAX_CHAMPIONS != 4
	|| CW_MAGIC != 0xea83f3
	|| CHAMP_MAX_SIZE != (MEM_SIZE / 6)
	|| DESC_SIZE != 2048
	|| PROG_NAME_SIZE != 128
	|| REG_IDX != 1
	|| REG_SIZE != 4
	|| REG_NUMBER != 16)
		error(NULL, 0,
"You are not allowed to modify .h content. Remember, 'Don't be a dick'.");
}
