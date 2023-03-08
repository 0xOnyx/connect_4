function alphabeta(node, depth, α, β, maximizingPlayer) is
	if depth = 0 or node is a terminal node then
		return the heuristic value of node
	if maximizingPlayer then
		value := −∞
	for each child of node do
		value := max(value, alphabeta(child, depth − 1, α, β, FALSE))
			if value > β then
				break (* β cutoff *)
		α := max(α, value)
		return value
	else
		value := +∞
		for each child of node do
			value := min(value, alphabeta(child, depth − 1, α, β, TRUE))
		if value < α then
			break (* α cutoff *)
		β := min(β, value)
	return value