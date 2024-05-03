import sys
import matplotlib.pyplot as plt
import numpy as np

def draw_quadratic_equation_graph(A, B, C):
    if A != 0:
        vertex_x = -B / (2 * A)
        range_x = max(10, abs(vertex_x) * 1.5)
    else:
        range_x = 10

    x = np.linspace(vertex_x - range_x, vertex_x + range_x, 400)

    # Calculate y values
    y = A * x**2 + B * x + C

    # Building a graph
    plt.figure(figsize=(10, 6))
    plt.plot(x, y, label='{}x^2 + {}x + {}'.format(A, B, C), color='red') # Set line color
    plt.xlabel('x')
    plt.ylabel('y')
    plt.axhline(0, color='black', linewidth=1) 
    plt.axvline(0, color='black', linewidth=1)
    plt.grid(True)
    plt.legend()
    plt.show()

# Get coefficients from command line arguments
if __name__ == "__main__":

    A, B, C = map(float, sys.argv[1:])
    draw_quadratic_equation_graph(A, B, C)
