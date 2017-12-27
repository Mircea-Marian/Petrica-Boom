# Petrica-Boom

Problem source: http://www.infoarena.ro/problema/boom

The protagonist of this problem is Petrica. What he does this time is something special: he plays with a rat. The latter is located in an underground gallery that presents itself as a succession of N-chambers arranged in line and numbered from 1 to N in order of their passage from one end to the other. Petrica does not know where the rat is located, but wants to exterminate it at all costs. Thus, he can detonate poison bombs in some of the gallery's rooms (sometimes even several simultaneously) to kill the rat. If it is in one of the gas chambers, it dies, otherwise the rat can go through it immediately after the bomb has detonated. Things are as follows: the two enemies play honestly so that after Petrica detonates a set of bombs that will explode simultaneously, the rat, if not dead, will move to one of the rooms adjacent to the one where they were (the rooms at the ends have only one neighboring room). Petrica has made an attack plan composed of M explosives. For each batch, the price of making it and the gas chambers that will explode is known. At every step, Petrica will choose only one of the M batches.

Input: On the first line in the boom.in input file there are two integers separated N and M , representing the number of gas rooms and the number of bits. The following M lines give information about each batch (they are numbered 1 to M in the order in which they are in the input file). Thus, on each line there are two integers P and Q, representing the price and the number of gas chambers in the batch. Then there are Q numbers (Q is not greater than 4) representing the gas chambers.

Output: On the first line of the boom.out output file you will find a whole number representing the minimum cost of a strategy that will result in the rat being dead. On the following line there is a T number representing the number of batches that will surely kill him. The following T lines contain the batch numbers used by Petrica (this is given in the order in which they were used).

Restrictions: 
1 ≤ N ≤ 20;
1 ≤ M ≤ 50;
The rat can not stand still;
If there are several solutions with the same minimum cost, one of them can be displayed;
A batch can be used several times
