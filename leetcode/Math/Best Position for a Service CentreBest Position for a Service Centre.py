class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        eps = 1e-7
        alpha = 1
        decay = 1e-3

        n = len(positions)

        x = sum(pos[0] for pos in positions) / n
        y = sum(pos[1] for pos in positions) / n

        dist = lambda xc, yc: sum(((xc - x) ** 2 + (yc - y) ** 2) ** 0.5 for x, y in positions)

        while True:
            xp, yp = x, y
            dx, dy = 0, 0
            for px, py in positions:
                dx += (x - px) / (sqrt((x - px) ** 2 + (y - py) ** 2) + eps)
                dy += (y - py) / (sqrt((x - px) ** 2 + (y - py) ** 2) + eps)
            x -= alpha * dx
            y -= alpha * dy

            if sqrt((x - xp) ** 2 + (y - yp) ** 2) < eps:
                break

            alpha *= (1 - decay)

        return dist(x, y)            