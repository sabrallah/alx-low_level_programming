#!/usr/bin/python3
"""
This script computes the perimeter of an island within a grid.
"""

def count_water_neighbors(grid, s, j):
    """
    Counts the number of water neighbors for a cell in a given grid.
    """

    count = 0

    if s <= 0 or not grid[s - 1][j]:
        count += 1
    if j <= 0 or not grid[s][j - 1]:
        count += 1
    if j >= len(grid[s]) - 1 or not grid[s][j + 1]:
        count += 1
    if s >= len(grid) - 1 or not grid[s + 1][j]:
        count += 1

    return count

def calculate_island_perimeter(grid):
    """
    Calculates the perimeter of the island present in the grid.
    """

    perimeter = 0
    for s in range(len(grid)):
        for j in range(len(grid[s])):
            if grid[s][j]:
                perimeter += count_water_neighbors(grid, s, j)

    return perimeter
