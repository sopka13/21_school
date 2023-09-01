#!/bin/bash

echo "----------Test icoming args:----------"
ft_1()
{
	echo "##########./philo $args"
	./philo_one/philo_one $args
	# ./philo_two/philo_two $args
	# ./philo_three/philo_three $args
}
args=""
ft_1
args="0"
ft_1
args="0 0"
ft_1
args="0 0 0"
ft_1
args="0 0 0 0dsdsd"
ft_1
args="0 0 0 0 0sdsd"
ft_1
args="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
ft_1
args="-1"
ft_1
args="-1 -1"
ft_1
args="-1 -1 -1"
ft_1
args="-1 -1 -1 -1"
ft_1
args="-1 -1 -1 -1 -1"
ft_1
args="00000000000000000000000000000 0 0 0"
ft_1
args="1"
ft_1
args="1 1"
ft_1
args="1 1 1"
ft_1
args="1 1 1 1sdsd"
ft_1
args="1 1 1 1 1sdsd"
ft_1
args="1 1 1 1 1 1"
ft_1
args="1 1 1 1 -1"
ft_1
args="0000000000000000001 0000000000000000000001 000000000000000000000001 00000000000000000000000000001"
ft_1
args="a a a a"
ft_1
args="a"
ft_1
args="a b c d e"
ft_1
args="--1 1 2 3 4"
ft_1
