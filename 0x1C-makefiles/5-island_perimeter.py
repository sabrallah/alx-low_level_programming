#!/usr/bin/python3
"""
This script computes the perimeter of an island within a grid.
"""


def count_water_neighbors(grid, i, j):
    """
    Counts the number of water neighbors for a cell in a given grid.
    """

    count = 0

    if i <= 0 or not grid[i - 1][j]:
        count += 1
    if j <= 0 or not grid[i][j - 1]:
        count += 1
    if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
        count += 1
    if i >= len(grid) - 1 or not grid[i + 1][j]:
        count += 1

    return count


def calculate_island_perimeter(grid):
    """
    Calculates the perimeter of the island present in the grid.
    """

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                perimeter += count_water_neighbors(grid, i, j)

    return perimeter
