class graph():
    def __init__(self, vertices:int):
        self.V = vertices
        self.adj = [[] for i in range(vertices)]

    def add_edge(self, start:int, end:int):
        if end < self.V and end not in self.adj[start]:
            self.adj[start].append(end)

    def print_adj(self, start = -1):
        for i, nborlst in enumerate(self.adj):
            if start < 0 or i == start:
                print(chr(i + ord('A')), ":[", end="")
                for j, nbor in enumerate(nborlst):
                    if j == len(nborlst) - 1:
                        print(chr(nbor + ord('A')), "", end="")
                    else:
                        print(chr(nbor + ord('A')), ",", end="")
                print("]")

G = graph(5)
G.add_edge(0,1)
G.add_edge(0,3)
G.add_edge(1,2)
G.add_edge(3,2)
G.add_edge(3,4)

G.print_adj()

