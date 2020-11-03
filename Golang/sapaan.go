package main

import "fmt"

func main() {
	var nama string
	fmt.Print("Halo, siapa namamu? ")

	fmt.Scanln(&nama)

	fmt.Println("Hai " + nama + ". Terima kasih sudah mampir")
}
