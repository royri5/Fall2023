import UIKit


//working, just need to run the command line exe to give input, loc: v
// /Users/richyroy/Library/Developer/Xcode/DerivedData/GuessNum-dotxtvfcfivkzpdoaghfqnurqabo/Build/Products/Debug
let number = Int.random(in: 1...100)
let running = true
while running {
    let guess = Int(readLine()!)!
    if guess == number {
        print("Correct!")
        running == false
        break
    } else if guess > number {
        print("Too High!")
    } else if guess < number {
        print("Too Low!")
    }
}
