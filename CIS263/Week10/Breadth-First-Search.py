
# Reference: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

# Breadth-First-Search
# take graph input in form: {(1, 2), (2, 3), (3, 1), (3, 4), (4, 5)}
# bfs takes root vertex input in the form: 3

# Node class for vertices
class Node:
    def __init__(self, val):
        self.val = val
        self.neighbors = {}

    def addNeighbor(self, neighbor):
        if neighbor not in self.neighbors:
            new_neighbor = Node(neighbor)
            self.neighbors[neighbor] = new_neighbor

    def getNeighbors(self):
        return set(self.neighbors.keys())
    
    def getVal(self):
        return self.val

# Graph class
class Graph:
    def __init__ (self):
        return "Invalid input, please enter a set of edges"
    def __init__(self, edges):
        # exception handling
        if type(edges) != set:
            return "Invalid input, edges must be a set"
        for edge in edges:
            if type(edge) != tuple:
                return "Invalid input, edges must be a set of tuples"
            if len(edge) != 2:
                return "Invalid input, edges must be a set of tuples with two elements (cannot be a disconnected graph"
            for vertex in edge:
                if type(vertex) != int:
                    return "Invalid input, vertices must be integers"
        self.edges = edges
        self.vertices = {}
        self.addEdges()
        self.queue = []
        self.visited = []

    def addEdges(self):
        for edge in self.edges:
            for vertex in edge:
                if vertex not in self.vertices:
                    new_node = Node(vertex)
                    #dictionary with vertex as key and node as value
                    self.vertices[vertex] = new_node
                    

        for edge in self.edges:
            self.vertices[edge[0]].addNeighbor(self.vertices[edge[1]].val)
            self.vertices[edge[1]].addNeighbor(self.vertices[edge[0]].val)


    def getEdges(self):
        return self.edges
    
    def printVertices(self):
        return set(self.vertices.keys())
    
    def getVertices(self):
        return set(self.vertices.keys())
    
    # recursively search through graph
    def bfs(self, root):
        self.visited = []
        self.queue = []
        # exception handling
        if type(root) != int:
            return "Invalid input"

        if root not in self.vertices:
            return "Vertex not in graph"
        self.queue.append(root)
        self.visited.append(root)
        self.queue.pop(0)
        for neighbor in self.vertices[root].getNeighbors():
            if neighbor not in self.visited:
                self.visited.append(neighbor)
                self.queue.append(neighbor)

        if len(self.queue) > 0:
            return self.bfs_helper()
        else:
            return self.visited
    
    def bfs_helper(self):
        if len(self.queue) > 0:
            for neighbor in self.vertices[self.queue[0]].getNeighbors():
                if neighbor not in self.visited:
                    self.visited.append(neighbor)
                    self.queue.append(neighbor)
            self.queue.pop(0)
            return self.bfs_helper()
        else:
            return self.visited


graph = Graph({(1, 2), (2, 3), (3, 1), (3, 4), (4, 5)})

print(graph.bfs(3))