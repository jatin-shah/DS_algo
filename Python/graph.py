class graph():
    def __init__(self, vertices:int):
        self.V = vertices
        self.adj = [[] for i in range(vertices)]

    def add_edge(self, start:int, end:int):
        if end < self.V and end not in self.adj[start]:
            self.adj[start].append(end)

    def print_neighbors(self, start = -1):
        for index, nborlst in enumerate(self.adj):
            if start < 0 or index == start:
                print(chr(index + ord('A')), ":[", end="")
                for nbor in nborlst:
                    print(chr(nbor + ord('A')), ",", end="")
                print("]")

G = graph(5)
G.add_edge(0,1)
G.add_edge(0,3)
G.add_edge(1,2)
G.add_edge(3,2)
G.add_edge(3,4)

G.print_neighbors()

