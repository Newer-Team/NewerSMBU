# 6/30/16 by RoadrunnerWMC
# Maybe I can make something useful here :P

import itertools

import matplotlib.path as mpath
import matplotlib.patches as mpatches
import matplotlib.pyplot as plt
import numpy


def get_closest_point(x0, y0, Ax, Ay, Bx, By):
    """
    Return the point on the line segment defined by (Ax, Ay) and (Bx, By)
    closest to (x0, y0).
    """

    if (Ax, Ay) == (Bx, By): # There is no line segment
        return Ax, Ay
    elif Ay == By: # The line is horizontal
        if Bx < Ax:
            Ax, Ay, Bx, By = Bx, By, Ax, Ay
        if x0 <= Ax:
            return Ax, Ay
        elif x0 >= Bx:
            return Bx, By
        return x0, Ay
    elif Ax == Bx: # The line is vertical
        if By < Ay:
            Ax, Ay, Bx, By = Bx, By, Ax, Ay
        if y0 < Ay:
            return Ax, Ay
        elif y0 > By:
            return Bx, By
        return Ax, y0
    else: # The line is some sort of diagonal
        # http://stackoverflow.com/a/5205747/4718769
        if Bx < Ax:
            Ax, Ay, Bx, By = Bx, By, Ax, Ay

        aTop = Ay > By
        m = -(Bx - Ax) / (By - Ay)

        f = (x0 - Ax) * m + Ay
        if aTop and y0 > f or not aTop and y0 < f:
            return (Ax, Ay)

        g = (x0 - Bx) * m + By
        if aTop and y0 < g or not aTop and y0 > g:
            return (Bx, By)

        # http://stackoverflow.com/a/5205909/4718769
        m1 = (By - Ay) / (Bx - Ax)
        m2 = -1 / m1
        x3 = (m1 * Ax - m2 * x0 + y0 - Ay) / (m1 - m2)
        y3 = m2 * (x3 - x0) + y0
        return (x3, y3)


def pairwise(iterable):
    """
    s -> (s0,s1), (s1,s2), (s2, s3), ...
    https://docs.python.org/3/library/itertools.html
    """
    a, b = itertools.tee(iterable)
    next(b, None)
    return zip(a, b)


def gravityAt(path, x, y):
    """
    Gravity at some place. The vector returned is guaranteed to be normalized
    or the zero vector.
    The first and last nodes of path should not be the same -- it is assumed
    to be a closed curve.
    """
    path = path + [path[0],] # close the curve, being careful to create a new
                             # list and avoid modifying the one passed to us

    u, v = 0, 0
    bestDistSq = 99999999
    for (x1, y1), (x2, y2) in pairwise(path):
        xc, yc = get_closest_point(x, y, x1, y1, x2, y2)
        distSq = (xc - x) ** 2 + (yc - y) ** 2
        if distSq < bestDistSq:
            bestDistSq = distSq

            u, v = xc - x, yc - y

    mag = bestDistSq ** 0.5
    if mag == 0: mag = 1
    return u / mag, v / mag



########################################################################
########################################################################
########################################################################
########################################################################



def makeGravity(path):
    """
    Make gravity
    """

    numThings = 100 # larger: slower but more accurate
    Y, X = numpy.mgrid[-6:6:numThings*1j, -6:6:numThings*1j]

    U = numpy.zeros((numThings, numThings))
    V = numpy.zeros((numThings, numThings))
    for y in range(numThings):
        for x in range(numThings):
            U[y, x], V[y, x] = gravityAt(path, float(X[0, x]), float(Y[y, 0]))

    return X, Y, U, V


def main():
    """
    Do stuff
    """

    fig, ax = plt.subplots()

    path = [ # Bent L
        (-3, 3),
        (-1, 3),
        (0, -1),
        (3, 0),
        (3, -2),
        (-3, -3),
        (-3, 3),
        ]
    # path = [ # Straight U
    #     (-3, 3),
    #     (-2, 3),
    #     (-2, -2),
    #     (2, -2),
    #     (2, 3),
    #     (3, 3),
    #     (3, -3),
    #     (-3, -3),
    #     (-3, 3)
    #     ]
    x = [node[0] for node in path]
    y = [node[1] for node in path]
    line, = ax.plot(x, y, 'go-')

    X, Y, U, V = makeGravity(path[:-1])

    strm = ax.streamplot(X, Y, U, V, linewidth=2, cmap=plt.cm.autumn)

    ax.grid()
    ax.axis('equal')
    plt.show()


if __name__ == '__main__': main()
