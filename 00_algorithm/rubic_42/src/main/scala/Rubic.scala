import scala.collection.mutable.ArrayBuffer

class Rubic {

  // Blue
  private val front: Array[Array[Char]] =
    Array(Array('B', 'B', 'B'), Array('B', 'B', 'B'), Array('B', 'B', 'B'))
  // Yellow
  private val up: Array[Array[Char]] =
    Array(Array('Y', 'Y', 'Y'), Array('Y', 'Y', 'Y'), Array('Y', 'Y', 'Y'))
  // White
  private val down: Array[Array[Char]] =
    Array(Array('W', 'W', 'W'), Array('W', 'W', 'W'), Array('W', 'W', 'W'))
  // Red
  private val right: Array[Array[Char]] =
    Array(Array('R', 'R', 'R'), Array('R', 'R', 'R'), Array('R', 'R', 'R'))
  // Orange
  private val left: Array[Array[Char]] =
    Array(Array('O', 'O', 'O'), Array('O', 'O', 'O'), Array('O', 'O', 'O'))
  // Green
  private val back: Array[Array[Char]] =
    Array(Array('G', 'G', 'G'), Array('G', 'G', 'G'), Array('G', 'G', 'G'))
  private val all_sides: Array[Array[Array[Char]]] =
    Array(front, up, down, right, left, back)

//  private def check_complete_crest(target_side: Array[Array[Char]]): Boolean = {
//    if (target_side.head(1) == target_side.apply(1)(0) &&
//      target_side.apply(1)(0) == target_side.apply(1)(1) &&
//      target_side.apply(1)(1) == target_side.apply(1)(2) &&
//      target_side.apply(1)(2) == target_side.last(1))
//      true
//    else
//      false
//  }
//  private def check_side_complete(target_side: Array[Array[Char]]): Boolean = {
//    if (target_side.forall(arr => arr.forall(ch => ch == target_side.head(0))))
//      return true
//    false
//  }
//  private def check_rubic_complete(): Boolean = {
//    if (all_sides.forall(arr_0 => arr_0.forall(arr_1 => arr_1.forall(ch => ch == arr_0(0)(0)))))
//      return true
//    false
//  }
//
//  private val steps = new ArrayBuffer[String].empty
//  private val start_side: Array[Array[Char]] = {
//    if (check_complete_crest(front))
//      front
//    else if (check_complete_crest(up))
//      up
//    else if (check_complete_crest(down))
//      down
//    else if (check_complete_crest(right))
//      right
//    else if (check_complete_crest(left))
//      left
//    else if (check_complete_crest(back))
//      back
//    else
//      front
//  }
//  private val target_color_positions: Array[Char] = {
//    start_side match {
//      case front => Array('B', 'W', 'R', 'Y', 'O', 'G')
//      case up =>    Array('Y', 'O', 'B', 'R', 'G', 'W')
//      case down =>  Array('W', 'R', 'B', 'O', 'G', 'Y')
//      case right => Array('R', 'W', 'G', 'Y', 'B', 'O')
//      case left =>  Array('O', 'W', 'B', 'Y', 'G', 'R')
//      case back =>  Array('G', 'W', 'O', 'Y', 'R', 'B')
//    }
//  }
//
//  private def get_current_pos_for_first_crest(start_side: Array[Array[Char]]): Unit = {
//    // States:
//    //  1. Crest complete
//    //  2. One or more sides complete
//    //  3. Neither sides complete
//
//  }
//
//  private def get_top_side(side: Array[Array[Char]]): Array[Array[Char]] = {
//    side match {
//      case front => up
//      case up => back
//      case down => front
//      case right => up
//      case left => up
//      case back => up
//    }
//  }
//  private def get_left_side(side: Array[Array[Char]]): Array[Array[Char]] = {
//    side match {
//      case front => left
//      case up => left
//      case down => left
//      case right => front
//      case left => back
//      case back => right
//    }
//  }
//  private def get_right_side(side: Array[Array[Char]]): Array[Array[Char]] = {
//    side match {
//      case front => right
//      case up => right
//      case down => right
//      case right => back
//      case left => front
//      case back => left
//    }
//  }
//  private def get_down_side(side: Array[Array[Char]]): Array[Array[Char]] = {
//    side match {
//      case front => down
//      case up => front
//      case down => back
//      case right => down
//      case left => down
//      case back => down
//    }
//  }
//
//  private def fill_accumulator_sides(start_side: Array[Array[Char]], target_color_arr: Array[Char]): Array[Int] = {
//    val tmp = Map[Char, Char](
//      start_side.head(0) -> get_top_side(start_side),
//      start_side.apply(1)(0) -> ' ',
//      start_side.apply(1)(2) -> ' ',
//      start_side.apply(2)(1) -> ' ')
////    for (i <- tmp.size)
////      if (tmp(i) == start_side.apply(1)(1) &&
////        )
//  }
//
//  private def collect_first_crest(start_side: Array[Array[Char]]): Unit = {
//    // States:
//    // +   1. Crest complete => return
//    //    2. One or more sides complete => collect other sides
//    //    3. Neither sides complete => collect all
//    val target_color_arr: Array[Char] = target_color_positions.drop(1).dropRight(1)
//    val accumulator_sides: Array[Int] = fill_accumulator_sides(start_side, target_color_arr)
//    while (!check_complete_crest(start_side)) {
//
//    }
//  }
//  private def collect_sides_centers(start_side: Array[Array[Char]]): Unit = {
//
//  }
//  private def collect_first_level(start_side: Array[Array[Char]]): Unit = {
//
//  }
//  private def collect_second_level(start_side: Array[Array[Char]]): Unit = {
//
//  }
//  private def collect_opposite_crest(start_side: Array[Array[Char]]): Unit = {
//
//  }
//  private def collect_opposite_side(start_side: Array[Array[Char]]): Unit = {
//
//  }
//  private def collect_last_level_corners(start_side: Array[Array[Char]]): Unit = {
//
//  }
//  private def collect_last_edges(start_side: Array[Array[Char]]): Unit = {
//
//  }
//
//  def collect_rubic(): Unit = {
//    collect_first_crest(start_side)
//    collect_sides_centers(start_side)
//    collect_first_level(start_side)
//    collect_second_level(start_side)
//    collect_opposite_crest(start_side)
//    collect_opposite_side(start_side)
//    collect_last_level_corners(start_side)
//    collect_last_edges(start_side)
//  }
//  def show_rubic(): Unit = {
//    println("Rubic condition:")
//    println(s"Steps taken: ${steps.mkString}")
//    val str = "--|--|--|" +               back.last.reverse.mkString("|") +       "|--|--|--\n" +
//      "--|--|--|" +                       back.apply(1).reverse.mkString("|") +   "|--|--|--\n" +
//      "--|--|--|" +                       back.head.reverse.mkString("|") +       "|--|--|--\n" +
//      "--|--|--|" +                       up.head.mkString("|") +                 "|--|--|--\n" +
//      "--|--|--|" +                       up.apply(1).mkString("|") +             "|--|--|--\n" +
//      "--|--|--|" +                       up.last.mkString("|") +                 "|--|--|--\n" +
//      left.head.mkString("|") + "|" +     front.head.mkString("|") + "|" +        right.head.mkString("|") + "\n" +
//      left.apply(1).mkString("|") + "|" + front.apply(1).mkString("|") + "|" +    right.apply(1).mkString("|") + "\n" +
//      left.last.mkString("|") + "|" +     front.last.mkString("|") + "|" +        right.last.mkString("|") + "\n" +
//      "--|--|--|" +                       down.head.mkString("|") +               "|--|--|--\n" +
//      "--|--|--|" +                       down.apply(1).mkString("|") +           "|--|--|--\n" +
//      "--|--|--|" +                       down.last.mkString("|") +               "|--|--|--\n"
//    println(str)
//  }
//  def show_steps(): Unit = {
//    println(steps.mkString)
//  }
//  def F_front(): Unit = {
//    val tmp = List(
//      List(up.last(0), up.last(1), up.last(2)),                            // 0
//      List(right.apply(0).head, right.apply(1).head, right.apply(2).head), // 1
//      List(down.head(0), down.head(1), down.head(2)),                      // 2
//      List(left.apply(0).last, left.apply(1).last, left.apply(2).last),    // 3
//      List(front.head(0), front.head(1), front.head(2)),                   // 4
//      List(front.apply(1)(0), front.apply(1)(1), front.apply(1)(2)),       // 5
//      List(front.last(0), front.last(1), front.last(2))                    // 6
//    )
//    right(0)(0) = tmp(0)(0)
//    right(1)(0) = tmp(0)(1)
//    right(2)(0) = tmp(0)(2)
//
//    down(0)(0) =  tmp(1)(2)
//    down(0)(1) =  tmp(1)(1)
//    down(0)(2) =  tmp(1)(0)
//
//    left(0)(2) =  tmp(2)(0)
//    left(1)(2) =  tmp(2)(1)
//    left(2)(2) =  tmp(2)(2)
//
//    up(2)(2) =    tmp(3)(0)
//    up(2)(1) =    tmp(3)(1)
//    up(2)(0) =    tmp(3)(2)
//
//    front(0)(0) = tmp(6)(0)
//    front(0)(1) = tmp(5)(0)
//    front(0)(2) = tmp(4)(0)
//    front(1)(2) = tmp(4)(1)
//    front(2)(2) = tmp(4)(2)
//    front(2)(1) = tmp(5)(2)
//    front(1)(0) = tmp(6)(1)
//    front(2)(0) = tmp(6)(2)
//
//    steps += " F"
//  }
//  def F_front_double(): Unit = {
//    val tmp = List(
//      List(up.last(0), up.last(1), up.last(2)), // 0
//      List(right.apply(0).head, right.apply(1).head, right.apply(2).head), // 1
//      List(down.head(0), down.head(1), down.head(2)), // 2
//      List(left.apply(0).last, left.apply(1).last, left.apply(2).last), // 3
//      List(front.head(0), front.head(1), front.head(2)), // 4
//      List(front.apply(1)(0), front.apply(1)(1), front.apply(1)(2)), // 5
//      List(front.last(0), front.last(1), front.last(2)) // 6
//    )
//    right(0)(0) = tmp(3)(2)
//    right(1)(0) = tmp(3)(1)
//    right(2)(0) = tmp(3)(0)
//
//    down(0)(0) = tmp(0)(2)
//    down(0)(1) = tmp(0)(1)
//    down(0)(2) = tmp(0)(0)
//
//    left(0)(2) = tmp(1)(2)
//    left(1)(2) = tmp(1)(1)
//    left(2)(2) = tmp(1)(0)
//
//    up(2)(0) = tmp(2)(2)
//    up(2)(1) = tmp(2)(1)
//    up(2)(2) = tmp(2)(0)
//
//    front(0)(0) = tmp(6)(2)
//    front(0)(1) = tmp(6)(1)
//    front(0)(2) = tmp(6)(0)
//    front(1)(2) = tmp(5)(0)
//    front(2)(2) = tmp(4)(0)
//    front(2)(1) = tmp(4)(1)
//    front(2)(0) = tmp(4)(2)
//    front(1)(0) = tmp(5)(2)
//
//    steps += " F2"
//  }
//  def F_back(): Unit = {
//    val tmp = List(
//      List(up.last(0), up.last(1), up.last(2)), // 0
//      List(right.apply(0).head, right.apply(1).head, right.apply(2).head), // 1
//      List(down.head(0), down.head(1), down.head(2)), // 2
//      List(left.apply(0).last, left.apply(1).last, left.apply(2).last), // 3
//      List(front.head(0), front.head(1), front.head(2)), // 4
//      List(front.apply(1)(0), front.apply(1)(1), front.apply(1)(2)), // 5
//      List(front.last(0), front.last(1), front.last(2)) // 6
//    )
//    right(0)(0) = tmp(2)(2)
//    right(1)(0) = tmp(2)(1)
//    right(2)(0) = tmp(2)(0)
//
//    down(0)(0) = tmp(3)(0)
//    down(0)(1) = tmp(3)(1)
//    down(0)(2) = tmp(3)(2)
//
//    left(0)(2) = tmp(0)(2)
//    left(1)(2) = tmp(0)(1)
//    left(2)(2) = tmp(0)(0)
//
//    up(2)(0) = tmp(1)(0)
//    up(2)(1) = tmp(1)(1)
//    up(2)(2) = tmp(1)(2)
//
//    front(0)(0) = tmp(4)(2)
//    front(0)(1) = tmp(5)(2)
//    front(0)(2) = tmp(6)(2)
//    front(1)(2) = tmp(6)(1)
//    front(2)(2) = tmp(6)(0)
//    front(2)(1) = tmp(5)(0)
//    front(1)(0) = tmp(4)(1)
//    front(2)(0) = tmp(4)(0)
//
//    steps += " F'"
//  }
//  def F_back_double(): Unit = {
//    val tmp = List(
//      List(up.last(0), up.last(1), up.last(2)), // 0
//      List(right.apply(0).head, right.apply(1).head, right.apply(2).head), // 1
//      List(down.head(0), down.head(1), down.head(2)), // 2
//      List(left.apply(0).last, left.apply(1).last, left.apply(2).last), // 3
//      List(front.head(0), front.head(1), front.head(2)), // 4
//      List(front.apply(1)(0), front.apply(1)(1), front.apply(1)(2)), // 5
//      List(front.last(0), front.last(1), front.last(2)) // 6
//    )
//    right(0)(0) = tmp(3)(2)
//    right(1)(0) = tmp(3)(1)
//    right(2)(0) = tmp(3)(0)
//
//    down(0)(0) = tmp(0)(2)
//    down(0)(1) = tmp(0)(1)
//    down(0)(2) = tmp(0)(0)
//
//    left(0)(2) = tmp(1)(2)
//    left(1)(2) = tmp(1)(1)
//    left(2)(2) = tmp(1)(0)
//
//    up(2)(2) = tmp(2)(0)
//    up(2)(1) = tmp(2)(1)
//    up(2)(0) = tmp(2)(2)
//
//    front(0)(0) = tmp(6)(2)
//    front(0)(1) = tmp(6)(1)
//    front(0)(2) = tmp(6)(0)
//    front(1)(2) = tmp(5)(0)
//    front(2)(2) = tmp(4)(0)
//    front(2)(1) = tmp(4)(1)
//    front(2)(0) = tmp(4)(2)
//    front(1)(0) = tmp(5)(2)
//
//    steps += " F2'"
//  }
//  def U_front(): Unit = {
//    val tmp = List(
//      List(back.head(0), back.head(1), back.head(2)), // 0
//      List(right.head(0), right.head(1), right.head(2)), // 1
//      List(front.head(0), front.head(1), front.head(2)), // 2
//      List(left.head(0), left.head(1), left.head(2)), // 3
//      List(up.head(0), up.head(1), up.head(2)), // 4
//      List(up.apply(1)(0), up.apply(1)(1), up.apply(1)(2)), // 5
//      List(up.last(0), up.last(1), up.last(2)) // 6
//    )
//    right(0)(0) = tmp(0)(0)
//    right(0)(1) = tmp(0)(1)
//    right(0)(2) = tmp(0)(2)
//
//    front(0)(0) = tmp(1)(0)
//    front(0)(1) = tmp(1)(1)
//    front(0)(2) = tmp(1)(2)
//
//    left(0)(0) = tmp(2)(0)
//    left(0)(1) = tmp(2)(1)
//    left(0)(2) = tmp(2)(2)
//
//    back(0)(0) = tmp(3)(0)
//    back(0)(1) = tmp(3)(1)
//    back(0)(2) = tmp(3)(2)
//
//    up(0)(0) = tmp(6)(0)
//    up(0)(1) = tmp(5)(0)
//    up(0)(2) = tmp(4)(0)
//    up(1)(2) = tmp(4)(1)
//    up(2)(2) = tmp(4)(2)
//    up(2)(1) = tmp(5)(2)
//    up(2)(0) = tmp(6)(2)
//    up(1)(0) = tmp(6)(1)
//
//    steps += " U"
//  }
//  def U_front_double(): Unit = {
//    val tmp = List(
//      List(back.head(0), back.head(1), back.head(2)), // 0
//      List(right.head(0), right.head(1), right.head(2)), // 1
//      List(front.head(0), front.head(1), front.head(2)), // 2
//      List(left.head(0), left.head(1), left.head(2)), // 3
//      List(up.head(0), up.head(1), up.head(2)), // 4
//      List(up.apply(1)(0), up.apply(1)(1), up.apply(1)(2)), // 5
//      List(up.last(0), up.last(1), up.last(2)) // 6
//    )
//    right(0)(0) = tmp(3)(0)
//    right(0)(1) = tmp(3)(1)
//    right(0)(2) = tmp(3)(2)
//
//    front(0)(0) = tmp(0)(0)
//    front(0)(1) = tmp(0)(1)
//    front(0)(2) = tmp(0)(2)
//
//    left(0)(0) = tmp(1)(0)
//    left(0)(1) = tmp(1)(1)
//    left(0)(2) = tmp(1)(2)
//
//    back(0)(0) = tmp(2)(0)
//    back(0)(1) = tmp(2)(1)
//    back(0)(2) = tmp(2)(2)
//
//    up(0)(0) = tmp(6)(2)
//    up(0)(1) = tmp(6)(1)
//    up(0)(2) = tmp(6)(0)
//    up(1)(2) = tmp(5)(0)
//    up(2)(2) = tmp(4)(0)
//    up(2)(1) = tmp(4)(1)
//    up(2)(0) = tmp(4)(2)
//    up(1)(0) = tmp(5)(2)
//
//    steps += " U2"
//  }
//  def U_back(): Unit = {
//    val tmp = List(
//      List(back.head(0), back.head(1), back.head(2)), // 0
//      List(right.head(0), right.head(1), right.head(2)), // 1
//      List(front.head(0), front.head(1), front.head(2)), // 2
//      List(left.head(0), left.head(1), left.head(2)), // 3
//      List(up.head(0), up.head(1), up.head(2)), // 4
//      List(up.apply(1)(0), up.apply(1)(1), up.apply(1)(2)), // 5
//      List(up.last(0), up.last(1), up.last(2)) // 6
//    )
//    right(0)(0) = tmp(2)(0)
//    right(0)(1) = tmp(2)(1)
//    right(0)(2) = tmp(2)(2)
//
//    front(0)(0) = tmp(3)(0)
//    front(0)(1) = tmp(3)(1)
//    front(0)(2) = tmp(3)(2)
//
//    left(0)(0) = tmp(0)(0)
//    left(0)(1) = tmp(0)(1)
//    left(0)(2) = tmp(0)(2)
//
//    back(0)(0) = tmp(1)(0)
//    back(0)(1) = tmp(1)(1)
//    back(0)(2) = tmp(1)(2)
//
//    up(0)(0) = tmp(4)(2)
//    up(0)(1) = tmp(5)(2)
//    up(0)(2) = tmp(6)(2)
//    up(1)(2) = tmp(6)(1)
//    up(2)(2) = tmp(6)(0)
//    up(2)(1) = tmp(5)(0)
//    up(1)(0) = tmp(4)(1)
//    up(2)(0) = tmp(4)(0)
//
//    steps += " U'"
//  }
//  def U_back_double(): Unit = {
//    val tmp = List(
//      List(back.head(0), back.head(1), back.head(2)), // 0
//      List(right.head(0), right.head(1), right.head(2)), // 1
//      List(front.head(0), front.head(1), front.head(2)), // 2
//      List(left.head(0), left.head(1), left.head(2)), // 3
//      List(up.head(0), up.head(1), up.head(2)), // 4
//      List(up.apply(1)(0), up.apply(1)(1), up.apply(1)(2)), // 5
//      List(up.last(0), up.last(1), up.last(2)) // 6
//    )
//    right(0)(0) = tmp(3)(0)
//    right(0)(1) = tmp(3)(1)
//    right(0)(2) = tmp(3)(2)
//
//    front(0)(0) = tmp(0)(0)
//    front(0)(1) = tmp(0)(1)
//    front(0)(2) = tmp(0)(2)
//
//    left(0)(0) = tmp(1)(0)
//    left(0)(1) = tmp(1)(1)
//    left(0)(2) = tmp(1)(2)
//
//    back(0)(0) = tmp(2)(0)
//    back(0)(1) = tmp(2)(1)
//    back(0)(2) = tmp(2)(2)
//
//    up(0)(0) = tmp(6)(2)
//    up(0)(1) = tmp(6)(1)
//    up(0)(2) = tmp(6)(0)
//    up(1)(2) = tmp(5)(0)
//    up(2)(2) = tmp(4)(0)
//    up(2)(1) = tmp(4)(1)
//    up(2)(0) = tmp(4)(2)
//    up(1)(0) = tmp(5)(2)
//
//    steps += " U2'"
//  }
//  def D_front(): Unit = {
//    val tmp = List(
//      List(front.last(0), front.last(1), front.last(2)), // 0
//      List(right.last(0), right.last(1), right.last(2)), // 1
//      List(back.last(0), back.last(1), back.last(2)), // 2
//      List(left.last(0), left.last(1), left.last(2)), // 3
//      List(down.head(0), down.head(1), down.head(2)), // 4
//      List(down.apply(1)(0), down.apply(1)(1), down.apply(1)(2)), // 5
//      List(down.last(0), down.last(1), down.last(2)) // 6
//    )
//    right(2)(0) = tmp(0)(0)
//    right(2)(1) = tmp(0)(1)
//    right(2)(2) = tmp(0)(2)
//
//    back(2)(0) = tmp(1)(0)
//    back(2)(1) = tmp(1)(1)
//    back(2)(2) = tmp(1)(2)
//
//    left(2)(0) = tmp(2)(0)
//    left(2)(1) = tmp(2)(1)
//    left(2)(2) = tmp(2)(2)
//
//    front(2)(0) = tmp(3)(0)
//    front(2)(1) = tmp(3)(1)
//    front(2)(2) = tmp(3)(2)
//
//    down(0)(0) = tmp(6)(0)
//    down(0)(1) = tmp(5)(0)
//    down(0)(2) = tmp(4)(0)
//    down(1)(2) = tmp(4)(1)
//    down(2)(2) = tmp(4)(2)
//    down(2)(1) = tmp(5)(2)
//    down(1)(0) = tmp(6)(1)
//    down(2)(0) = tmp(6)(2)
//
//    steps += " D"
//  }
//  def D_front_double(): Unit = {
//    val tmp = List(
//      List(front.last(0), front.last(1), front.last(2)), // 0
//      List(right.last(0), right.last(1), right.last(2)), // 1
//      List(back.last(0), back.last(1), back.last(2)), // 2
//      List(left.last(0), left.last(1), left.last(2)), // 3
//      List(down.head(0), down.head(1), down.head(2)), // 4
//      List(down.apply(1)(0), down.apply(1)(1), down.apply(1)(2)), // 5
//      List(down.last(0), down.last(1), down.last(2)) // 6
//    )
//    right(2)(0) = tmp(3)(0)
//    right(2)(1) = tmp(3)(1)
//    right(2)(2) = tmp(3)(2)
//
//    back(2)(0) = tmp(0)(0)
//    back(2)(1) = tmp(0)(1)
//    back(2)(2) = tmp(0)(2)
//
//    left(2)(0) = tmp(1)(0)
//    left(2)(1) = tmp(1)(1)
//    left(2)(2) = tmp(1)(2)
//
//    front(2)(0) = tmp(2)(0)
//    front(2)(1) = tmp(2)(1)
//    front(2)(2) = tmp(2)(2)
//
//    down(0)(0) = tmp(6)(2)
//    down(0)(1) = tmp(6)(1)
//    down(0)(2) = tmp(6)(0)
//    down(1)(2) = tmp(5)(0)
//    down(2)(2) = tmp(4)(0)
//    down(2)(1) = tmp(4)(1)
//    down(2)(0) = tmp(4)(2)
//    down(1)(0) = tmp(5)(2)
//
//    steps += " D2"
//  }
//  def D_back(): Unit = {
//    val tmp = List(
//      List(front.last(0), front.last(1), front.last(2)), // 0
//      List(right.last(0), right.last(1), right.last(2)), // 1
//      List(back.last(0), back.last(1), back.last(2)), // 2
//      List(left.last(0), left.last(1), left.last(2)), // 3
//      List(down.head(0), down.head(1), down.head(2)), // 4
//      List(down.apply(1)(0), down.apply(1)(1), down.apply(1)(2)), // 5
//      List(down.last(0), down.last(1), down.last(2)) // 6
//    )
//    right(2)(0) = tmp(2)(0)
//    right(2)(1) = tmp(2)(1)
//    right(2)(2) = tmp(2)(2)
//
//    back(2)(0) = tmp(3)(0)
//    back(2)(1) = tmp(3)(1)
//    back(2)(2) = tmp(3)(2)
//
//    left(2)(0) = tmp(0)(0)
//    left(2)(1) = tmp(0)(1)
//    left(2)(2) = tmp(0)(2)
//
//    front(2)(0) = tmp(1)(0)
//    front(2)(1) = tmp(1)(1)
//    front(2)(2) = tmp(1)(2)
//
//    down(0)(0) = tmp(4)(2)
//    down(0)(1) = tmp(5)(2)
//    down(0)(2) = tmp(6)(2)
//    down(1)(2) = tmp(6)(1)
//    down(2)(2) = tmp(6)(0)
//    down(2)(1) = tmp(5)(0)
//    down(1)(0) = tmp(4)(1)
//    down(2)(0) = tmp(4)(0)
//
//    steps += " D'"
//  }
//  def D_back_double(): Unit = {
//    val tmp = List(
//      List(front.last(0), front.last(1), front.last(2)), // 0
//      List(right.last(0), right.last(1), right.last(2)), // 1
//      List(back.last(0), back.last(1), back.last(2)), // 2
//      List(left.last(0), left.last(1), left.last(2)), // 3
//      List(down.head(0), down.head(1), down.head(2)), // 4
//      List(down.apply(1)(0), down.apply(1)(1), down.apply(1)(2)), // 5
//      List(down.last(0), down.last(1), down.last(2)) // 6
//    )
//    right(2)(0) = tmp(3)(0)
//    right(2)(1) = tmp(3)(1)
//    right(2)(2) = tmp(3)(2)
//
//    back(2)(0) = tmp(0)(0)
//    back(2)(1) = tmp(0)(1)
//    back(2)(2) = tmp(0)(2)
//
//    left(2)(0) = tmp(1)(0)
//    left(2)(1) = tmp(1)(1)
//    left(2)(2) = tmp(1)(2)
//
//    front(2)(0) = tmp(2)(0)
//    front(2)(1) = tmp(2)(1)
//    front(2)(2) = tmp(2)(2)
//
//    down(0)(0) = tmp(6)(2)
//    down(0)(1) = tmp(6)(1)
//    down(0)(2) = tmp(6)(0)
//    down(1)(2) = tmp(5)(0)
//    down(2)(2) = tmp(4)(0)
//    down(2)(1) = tmp(4)(1)
//    down(2)(0) = tmp(4)(2)
//    down(1)(0) = tmp(5)(2)
//
//    steps += " D2'"
//  }
//  def R_front(): Unit = {
//    val tmp = List(
//      List(up.head(2), up.apply(1)(2), up.last(2)), // 0
//      List(back.head(0), back.apply(1)(0), back.last(0)), // 1
//      List(down.head(2), down.apply(1)(2), down.last(2)), // 2
//      List(front.head(2), front.apply(1)(2), front.last(2)), // 3
//      List(right.head(0), right.head(1), right.head(2)), // 4
//      List(right.apply(1)(0), right.apply(1)(1), right.apply(1)(2)), // 5
//      List(right.last(0), right.last(1), right.last(2)) // 6
//    )
//    back(0)(0) = tmp(0)(2)
//    back(1)(0) = tmp(0)(1)
//    back(2)(0) = tmp(0)(0)
//
//    down(0)(2) = tmp(1)(2)
//    down(1)(2) = tmp(1)(1)
//    down(2)(2) = tmp(1)(0)
//
//    front(0)(2) = tmp(2)(0)
//    front(1)(2) = tmp(2)(1)
//    front(2)(2) = tmp(2)(2)
//
//    up(0)(2) = tmp(3)(0)
//    up(1)(2) = tmp(3)(1)
//    up(2)(2) = tmp(3)(2)
//
//    right(0)(0) = tmp(6)(0)
//    right(0)(1) = tmp(5)(0)
//    right(0)(2) = tmp(4)(0)
//    right(1)(2) = tmp(4)(1)
//    right(2)(2) = tmp(4)(2)
//    right(2)(1) = tmp(5)(2)
//    right(1)(0) = tmp(6)(1)
//    right(2)(0) = tmp(6)(2)
//
//    steps += " R"
//  }
//  def R_front_double(): Unit = {
//    val tmp = List(
//      List(up.head(2), up.apply(1)(2), up.last(2)), // 0
//      List(back.head(0), back.apply(1)(0), back.last(0)), // 1
//      List(down.head(2), down.apply(1)(2), down.last(2)), // 2
//      List(front.head(2), front.apply(1)(2), front.last(2)), // 3
//      List(right.head(0), right.head(1), right.head(2)), // 4
//      List(right.apply(1)(0), right.apply(1)(1), right.apply(1)(2)), // 5
//      List(right.last(0), right.last(1), right.last(2)) // 6
//    )
//    back(0)(0) = tmp(3)(2)
//    back(1)(0) = tmp(3)(1)
//    back(2)(0) = tmp(3)(0)
//
//    down(0)(2) = tmp(0)(0)
//    down(1)(2) = tmp(0)(1)
//    down(2)(2) = tmp(0)(2)
//
//    front(0)(2) = tmp(1)(2)
//    front(1)(2) = tmp(1)(1)
//    front(2)(2) = tmp(1)(0)
//
//    up(0)(2) = tmp(2)(0)
//    up(1)(2) = tmp(2)(1)
//    up(2)(2) = tmp(2)(2)
//
//    right(0)(0) = tmp(6)(2)
//    right(0)(1) = tmp(6)(1)
//    right(0)(2) = tmp(6)(0)
//    right(1)(2) = tmp(5)(0)
//    right(2)(2) = tmp(4)(0)
//    right(2)(1) = tmp(4)(1)
//    right(2)(0) = tmp(4)(2)
//    right(1)(0) = tmp(5)(2)
//
//    steps += " R2"
//  }
//  def R_back(): Unit = {
//    val tmp = List(
//      List(up.head(2), up.apply(1)(2), up.last(2)), // 0
//      List(back.head(0), back.apply(1)(0), back.last(0)), // 1
//      List(down.head(2), down.apply(1)(2), down.last(2)), // 2
//      List(front.head(2), front.apply(1)(2), front.last(2)), // 3
//      List(right.head(0), right.head(1), right.head(2)), // 4
//      List(right.apply(1)(0), right.apply(1)(1), right.apply(1)(2)), // 5
//      List(right.last(0), right.last(1), right.last(2)) // 6
//    )
//    back(0)(0) = tmp(2)(2)
//    back(1)(0) = tmp(2)(1)
//    back(2)(0) = tmp(2)(0)
//
//    down(0)(2) = tmp(3)(0)
//    down(1)(2) = tmp(3)(1)
//    down(2)(2) = tmp(3)(2)
//
//    front(0)(2) = tmp(0)(0)
//    front(1)(2) = tmp(0)(1)
//    front(2)(2) = tmp(0)(2)
//
//    up(0)(2) = tmp(1)(2)
//    up(1)(2) = tmp(1)(1)
//    up(2)(2) = tmp(1)(0)
//
//    right(0)(0) = tmp(4)(2)
//    right(0)(1) = tmp(5)(2)
//    right(0)(2) = tmp(6)(2)
//    right(1)(2) = tmp(6)(1)
//    right(2)(2) = tmp(6)(0)
//    right(2)(1) = tmp(5)(0)
//    right(1)(0) = tmp(4)(1)
//    right(2)(0) = tmp(4)(0)
//
//    steps += " R'"
//  }
//  def R_back_double(): Unit = {
//    val tmp = List(
//      List(up.head(2), up.apply(1)(2), up.last(2)), // 0
//      List(back.head(0), back.apply(1)(0), back.last(0)), // 1
//      List(down.head(2), down.apply(1)(2), down.last(2)), // 2
//      List(front.head(2), front.apply(1)(2), front.last(2)), // 3
//      List(right.head(0), right.head(1), right.head(2)), // 4
//      List(right.apply(1)(0), right.apply(1)(1), right.apply(1)(2)), // 5
//      List(right.last(0), right.last(1), right.last(2)) // 6
//    )
//    back(0)(0) = tmp(3)(2)
//    back(1)(0) = tmp(3)(1)
//    back(2)(0) = tmp(3)(0)
//
//    down(0)(2) = tmp(0)(0)
//    down(1)(2) = tmp(0)(1)
//    down(2)(2) = tmp(0)(2)
//
//    front(0)(2) = tmp(1)(2)
//    front(1)(2) = tmp(1)(1)
//    front(2)(2) = tmp(1)(0)
//
//    up(0)(2) = tmp(2)(0)
//    up(1)(2) = tmp(2)(1)
//    up(2)(2) = tmp(2)(2)
//
//    right(0)(0) = tmp(6)(2)
//    right(0)(1) = tmp(6)(1)
//    right(0)(2) = tmp(6)(0)
//    right(1)(2) = tmp(5)(0)
//    right(2)(2) = tmp(4)(0)
//    right(2)(1) = tmp(4)(1)
//    right(2)(0) = tmp(4)(2)
//    right(1)(0) = tmp(5)(2)
//
//    steps += " R2'"
//  }
//  def L_front(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.apply(1)(0), up.last(0)), // 0
//      List(front.head(0), front.apply(1)(0), front.last(0)), // 1
//      List(down.head(0), down.apply(1)(0), down.last(0)), // 2
//      List(back.head(2), back.apply(1)(2), back.last(2)), // 3
//      List(left.head(0), left.head(1), left.head(2)), // 4
//      List(left.apply(1)(0), left.apply(1)(1), left.apply(1)(2)), // 5
//      List(left.last(0), left.last(1), left.last(2)) // 6
//    )
//    front(0)(0) = tmp(0)(0)
//    front(1)(0) = tmp(0)(1)
//    front(2)(0) = tmp(0)(2)
//
//    down(0)(0) = tmp(1)(0)
//    down(1)(0) = tmp(1)(1)
//    down(2)(0) = tmp(1)(2)
//
//    back(0)(2) = tmp(2)(2)
//    back(1)(2) = tmp(2)(1)
//    back(2)(2) = tmp(2)(0)
//
//    up(0)(0) = tmp(3)(2)
//    up(1)(0) = tmp(3)(1)
//    up(2)(0) = tmp(3)(0)
//
//    left(0)(0) = tmp(6)(0)
//    left(0)(1) = tmp(5)(0)
//    left(0)(2) = tmp(4)(0)
//    left(1)(2) = tmp(4)(1)
//    left(2)(2) = tmp(4)(2)
//    left(2)(1) = tmp(5)(2)
//    left(1)(0) = tmp(6)(1)
//    left(2)(0) = tmp(6)(2)
//
//    steps += " L"
//  }
//  def L_front_double(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.apply(1)(0), up.last(0)), // 0
//      List(front.head(0), front.apply(1)(0), front.last(0)), // 1
//      List(down.head(0), down.apply(1)(0), down.last(0)), // 2
//      List(back.head(2), back.apply(1)(2), back.last(2)), // 3
//      List(left.head(0), left.head(1), left.head(2)), // 4
//      List(left.apply(1)(0), left.apply(1)(1), left.apply(1)(2)), // 5
//      List(left.last(0), left.last(1), left.last(2)) // 6
//    )
//    front(0)(0) = tmp(3)(2)
//    front(1)(0) = tmp(3)(1)
//    front(2)(0) = tmp(3)(0)
//
//    down(0)(0) = tmp(0)(0)
//    down(1)(0) = tmp(0)(1)
//    down(2)(0) = tmp(0)(2)
//
//    back(0)(2) = tmp(1)(2)
//    back(1)(2) = tmp(1)(1)
//    back(2)(2) = tmp(1)(0)
//
//    up(0)(0) = tmp(2)(0)
//    up(1)(0) = tmp(2)(1)
//    up(2)(0) = tmp(2)(2)
//
//    left(0)(0) = tmp(6)(2)
//    left(0)(1) = tmp(6)(1)
//    left(0)(2) = tmp(6)(0)
//    left(1)(2) = tmp(5)(0)
//    left(2)(2) = tmp(4)(0)
//    left(2)(1) = tmp(4)(1)
//    left(2)(0) = tmp(4)(2)
//    left(1)(0) = tmp(5)(2)
//
//    steps += " L2"
//  }
//  def L_back(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.apply(1)(0), up.last(0)), // 0
//      List(front.head(0), front.apply(1)(0), front.last(0)), // 1
//      List(down.head(0), down.apply(1)(0), down.last(0)), // 2
//      List(back.head(2), back.apply(1)(2), back.last(2)), // 3
//      List(left.head(0), left.head(1), left.head(2)), // 4
//      List(left.apply(1)(0), left.apply(1)(1), left.apply(1)(2)), // 5
//      List(left.last(0), left.last(1), left.last(2)) // 6
//    )
//    front(0)(0) = tmp(2)(0)
//    front(1)(0) = tmp(2)(1)
//    front(2)(0) = tmp(2)(2)
//
//    down(0)(0) = tmp(3)(2)
//    down(1)(0) = tmp(3)(1)
//    down(2)(0) = tmp(3)(0)
//
//    back(0)(2) = tmp(0)(2)
//    back(1)(2) = tmp(0)(1)
//    back(2)(2) = tmp(0)(0)
//
//    up(0)(0) = tmp(1)(0)
//    up(1)(0) = tmp(1)(1)
//    up(2)(0) = tmp(1)(2)
//
//    left(0)(0) = tmp(4)(2)
//    left(0)(1) = tmp(5)(2)
//    left(0)(2) = tmp(6)(2)
//    left(1)(2) = tmp(6)(1)
//    left(2)(2) = tmp(6)(0)
//    left(2)(1) = tmp(5)(0)
//    left(1)(0) = tmp(4)(1)
//    left(2)(0) = tmp(4)(0)
//
//    steps += " L'"
//  }
//  def L_back_double(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.apply(1)(0), up.last(0)), // 0
//      List(front.head(0), front.apply(1)(0), front.last(0)), // 1
//      List(down.head(0), down.apply(1)(0), down.last(0)), // 2
//      List(back.head(2), back.apply(1)(2), back.last(2)), // 3
//      List(left.head(0), left.head(1), left.head(2)), // 4
//      List(left.apply(1)(0), left.apply(1)(1), left.apply(1)(2)), // 5
//      List(left.last(0), left.last(1), left.last(2)) // 6
//    )
//    front(0)(0) = tmp(3)(2)
//    front(1)(0) = tmp(3)(1)
//    front(2)(0) = tmp(3)(0)
//
//    down(0)(0) = tmp(0)(0)
//    down(1)(0) = tmp(0)(1)
//    down(2)(0) = tmp(0)(2)
//
//    back(0)(2) = tmp(1)(2)
//    back(1)(2) = tmp(1)(1)
//    back(2)(2) = tmp(1)(0)
//
//    up(0)(0) = tmp(2)(0)
//    up(1)(0) = tmp(2)(1)
//    up(2)(0) = tmp(2)(2)
//
//    left(0)(0) = tmp(6)(2)
//    left(0)(1) = tmp(6)(1)
//    left(0)(2) = tmp(6)(0)
//    left(1)(2) = tmp(5)(0)
//    left(2)(2) = tmp(4)(0)
//    left(2)(1) = tmp(4)(1)
//    left(2)(0) = tmp(4)(2)
//    left(1)(0) = tmp(5)(2)
//
//    steps += " L2'"
//  }
//  def B_front(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.head(1), up.head(2)), // 0
//      List(left.head(0), left.apply(1)(0), left.last(0)), // 1
//      List(down.last(0), down.last(1), down.last(2)), // 2
//      List(right.head(2), right.apply(1)(2), right.last(2)), // 3
//      List(back.head(0), back.head(1), back.head(2)), // 4
//      List(back.apply(1)(0), back.apply(1)(1), back.apply(1)(2)), // 5
//      List(back.last(0), back.last(1), back.last(2)) // 6
//    )
//    left(0)(0) = tmp(0)(2)
//    left(1)(0) = tmp(0)(1)
//    left(2)(0) = tmp(0)(0)
//
//    down(2)(0) = tmp(1)(0)
//    down(2)(1) = tmp(1)(1)
//    down(2)(2) = tmp(1)(2)
//
//    right(0)(2) = tmp(2)(2)
//    right(1)(2) = tmp(2)(1)
//    right(2)(2) = tmp(2)(0)
//
//    up(0)(0) = tmp(3)(0)
//    up(0)(1) = tmp(3)(1)
//    up(0)(2) = tmp(3)(2)
//
//    back(0)(0) = tmp(6)(0)
//    back(0)(1) = tmp(5)(0)
//    back(0)(2) = tmp(4)(0)
//    back(1)(2) = tmp(4)(1)
//    back(2)(2) = tmp(4)(2)
//    back(2)(1) = tmp(5)(2)
//    back(1)(0) = tmp(6)(1)
//    back(2)(0) = tmp(6)(2)
//
//    steps += " B"
//  }
//  def B_front_double(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.head(1), up.head(2)), // 0
//      List(left.head(0), left.apply(1)(0), left.last(0)), // 1
//      List(down.last(0), down.last(1), down.last(2)), // 2
//      List(right.head(2), right.apply(1)(2), right.last(2)), // 3
//      List(back.head(0), back.head(1), back.head(2)), // 4
//      List(back.apply(1)(0), back.apply(1)(1), back.apply(1)(2)), // 5
//      List(back.last(0), back.last(1), back.last(2)) // 6
//    )
//    left(0)(0) = tmp(3)(2)
//    left(1)(0) = tmp(3)(1)
//    left(2)(0) = tmp(3)(0)
//
//    down(2)(0) = tmp(0)(2)
//    down(2)(1) = tmp(0)(1)
//    down(2)(2) = tmp(0)(0)
//
//    right(0)(2) = tmp(1)(2)
//    right(1)(2) = tmp(1)(1)
//    right(2)(2) = tmp(1)(0)
//
//    up(0)(0) = tmp(2)(2)
//    up(0)(1) = tmp(2)(1)
//    up(0)(2) = tmp(2)(0)
//
//    back(0)(0) = tmp(6)(2)
//    back(0)(1) = tmp(6)(1)
//    back(0)(2) = tmp(6)(0)
//    back(1)(2) = tmp(5)(0)
//    back(2)(2) = tmp(4)(0)
//    back(2)(1) = tmp(4)(1)
//    back(2)(0) = tmp(4)(2)
//    back(1)(0) = tmp(5)(2)
//
//    steps += " B2"
//  }
//  def B_back(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.head(1), up.head(2)), // 0
//      List(left.head(0), left.apply(1)(0), left.last(0)), // 1
//      List(down.last(0), down.last(1), down.last(2)), // 2
//      List(right.head(2), right.apply(1)(2), right.last(2)), // 3
//      List(back.head(0), back.head(1), back.head(2)), // 4
//      List(back.apply(1)(0), back.apply(1)(1), back.apply(1)(2)), // 5
//      List(back.last(0), back.last(1), back.last(2)) // 6
//    )
//    left(0)(0) = tmp(2)(0)
//    left(1)(0) = tmp(2)(1)
//    left(2)(0) = tmp(2)(2)
//
//    down(2)(0) = tmp(3)(2)
//    down(2)(1) = tmp(3)(1)
//    down(2)(2) = tmp(3)(0)
//
//    right(0)(2) = tmp(0)(0)
//    right(1)(2) = tmp(0)(1)
//    right(2)(2) = tmp(0)(2)
//
//    up(0)(0) = tmp(1)(2)
//    up(0)(1) = tmp(1)(1)
//    up(0)(2) = tmp(1)(0)
//
//    back(0)(0) = tmp(4)(2)
//    back(0)(1) = tmp(5)(2)
//    back(0)(2) = tmp(6)(2)
//    back(1)(2) = tmp(6)(1)
//    back(2)(2) = tmp(6)(0)
//    back(2)(1) = tmp(5)(0)
//    back(1)(0) = tmp(4)(1)
//    back(2)(0) = tmp(4)(0)
//
//    steps += " B'"
//  }
//  def B_back_double(): Unit = {
//    val tmp = List(
//      List(up.head(0), up.head(1), up.head(2)), // 0
//      List(left.head(0), left.apply(1)(0), left.last(0)), // 1
//      List(down.last(0), down.last(1), down.last(2)), // 2
//      List(right.head(2), right.apply(1)(2), right.last(2)), // 3
//      List(back.head(0), back.head(1), back.head(2)), // 4
//      List(back.apply(1)(0), back.apply(1)(1), back.apply(1)(2)), // 5
//      List(back.last(0), back.last(1), back.last(2)) // 6
//    )
//    left(0)(0) = tmp(3)(2)
//    left(1)(0) = tmp(3)(1)
//    left(2)(0) = tmp(3)(0)
//
//    down(2)(0) = tmp(0)(2)
//    down(2)(1) = tmp(0)(1)
//    down(2)(2) = tmp(0)(0)
//
//    right(0)(2) = tmp(1)(2)
//    right(1)(2) = tmp(1)(1)
//    right(2)(2) = tmp(1)(0)
//
//    up(0)(0) = tmp(2)(2)
//    up(0)(1) = tmp(2)(1)
//    up(0)(2) = tmp(2)(0)
//
//    back(0)(0) = tmp(6)(2)
//    back(0)(1) = tmp(6)(1)
//    back(0)(2) = tmp(6)(0)
//    back(1)(2) = tmp(5)(0)
//    back(2)(2) = tmp(4)(0)
//    back(2)(1) = tmp(4)(1)
//    back(2)(0) = tmp(4)(2)
//    back(1)(0) = tmp(5)(2)
//
//    steps += " B2'"
//  }
}
