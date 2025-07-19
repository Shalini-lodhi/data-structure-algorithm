import (
    "sort"
)

func findRadius(houses []int, heaters []int) int {
    // Sort both arrays to apply binary search efficiently
    sort.Ints(houses)
    sort.Ints(heaters)

    maxDist := 0

    for _, house := range houses {
        // Find the index of the smallest heater >= house
        i := sort.Search(len(heaters), func(j int) bool {
            return heaters[j] >= house
        })

        // Calculate distance to nearest heater
        dist1 := 1 << 30 // large number
        if i < len(heaters) {
            dist1 = abs(heaters[i] - house)
        }
        dist2 := 1 << 30
        if i > 0 {
            dist2 = abs(heaters[i-1] - house)
        }

        // Minimum distance for this house
        minDist := min(dist1, dist2)

        // Keep track of the max distance needed
        if minDist > maxDist {
            maxDist = minDist
        }
    }

    return maxDist
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}