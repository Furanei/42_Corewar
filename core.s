# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    core.s                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbriffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 22:17:05 by mbriffau          #+#    #+#              #
#    Updated: 2018/04/17 22:17:20 by mbriffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name    "core"
.comment "champion"

live	%1
ld 		%57672193 ,r2
fork	%:zap
fork 	%:wall

ultiwall:
	live	%-1
	fork	%:zap
	add		r5,r5,r5
	zjmp	%:ultiwall

wall:
	live	%-1
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	st		r1, -423
	add		r5,r5,r5
	zjmp	%:wall

live:
	live	%-1
	add 	r9,r9,r9
	zjmp	%:live

zap:
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	live	%1
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
	st	r2, 256
