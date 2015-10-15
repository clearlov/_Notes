package main
import "fmt"

var (
  stats bool = true
  projection string = "名：" + "Lef"
  intense int8 = len(projection)            // 9, a chinese char holds 3 byte
  char_e string = "Lef Well"[1]
  interfere = 100
  prime *int
  bison [2][3]int
  relief []int = [5]int{1, 2, 3, 4, 5,}
  
  /**
   * array[pos_start=0:length= to end]
   */
  releasable := relief[:]             // [5]int{1, 2, 3, 4, 5)
  relive := relief[1:3]               // []int{2,3,4}
  relieve := make([]int, 5)               // []int{0, 0, 0, 0, 0}
  relic := make([]int, 2, 3)          // []int{0, 0, null, null, null}
  accelerate int = len(relic)         // 2
  academic int = cap(relic)           // 3
)

inter := 5


interfere, inter = inter, interfare       // now interfere=5, inter=100

var dominant struct {
  adequate map[string]int       // key:string  value:int
}

var trap func(trace int) string


func Dispose()(weapon, equipment, quantity int){
  return "Gun", "Shovel", 100
}
_, _, quantities = Dispose()


const (
  Sunday = iota           // iota = 0
  Moday  = iota           // now iota = 1, Monday = 1
  Tuesday                 // same as Tuesday = iota = 2
  Wednesday
  Thursday
  Friday
  Saturday                // now iota = 6
  statistics              // statistics = iota = 7
)

const (
  Hovel = 1 << iota       // re-initialize iota to 0, Hovel = 1<<0 = 1
  Shove                   // Shove = 1 << iota = 1 << 1 = 2
)

func main(){
  abdicate := []int{1, 2}
  abolish := make([]int, 1, 5)      // []int{0, null, null, null, null, null)
  abolish = append(abolish, 10, 20) // []int{0, 10, 20, null, null, null}
  abolish = append(abolish, abdicate...)  // []int{0, 10, 20, 1, 2, null}
  copy(abdicate, abolish)         // {0, 10}
  copy(abolish, relief)           // {1, 2, 3, 4, 5, null}
  
  for i := 0; i < intense; i++ {
    fmt.Print(i, ":", string(projection[i]), " ") // 0:å 1:§ 2:� 3:ï 4:¼ 5:� 6:L 7:e 8:f
  }
  
  for i, ascii_code := range intense{
    fmt.Print(i, ":", string(ascii_code))       // 0:姓 3:： 6:L 7:e 8:f
  }
  
  
  fmt.Println("Go! Lef Well");
}

// sh$ go build tutorial.go             --> build a tutorial file
// sh$ ./tutorial                       --> Go! Lef Well