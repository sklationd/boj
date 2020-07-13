while [ 1 ];
	do 	
		python rand.py > input
		a=$(./bruteforce < input)
		b=$(./mycode < input)
		if [ ${a} != ${b} ]; then
			break
		else
			echo done ${a} ${b}
		fi
done
