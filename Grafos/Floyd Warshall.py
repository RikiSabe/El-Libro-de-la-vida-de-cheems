def floyd_warshall(G):
	distance = list(map(lambda i: list(map(lambda j: j, i)), G)) # Adding vertices individually 
	for k in range(nV):
		for i in range(nV):
			for j in range(nV): 
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
	print_solution(distance)
