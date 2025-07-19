import (
	"sort"
)

func findRightInterval(intervals [][]int) []int {
    n := len(intervals)
    starts := make([][2]int, n)

    for i, interval := range intervals{
        starts[i] = [2]int{interval[0], i}
    }
    sort.Slice(starts, func(i,j int) bool{
        return starts[i][0] < starts[j][0]
    })

    result := make([]int, n)
    for i, interval := range intervals{
        end := interval[1]
        idx := sort.Search(n, func(j int)bool{
            return starts[j][0] >= end
        })
        if idx < n {
            result[i] = starts[idx][1]
        }else{
            result[i] = -1
        }
    }
    return result
}