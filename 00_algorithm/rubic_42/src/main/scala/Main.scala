import src.Rubic_new

/*
    Rubic
    Movies:
      - F   front movie clockwise;
      - F'  front movie counterclockwise;
      - F2  half turn front side clockwise;
      - U   up;
      - D   down;
      - R   right;
      - L   left;
      - B   back;

      Display rubic state:
    *** back ***
    ***  up  ***
    lft frnt rth
    *** down ***

    *** down ***          back(2)
    *** cntr ***          back(1)
    ***  up  ***          back(0)
    *** far  ***          up(0)
    *** cntr ***          up(1)
    *** near ***          up(2)
    top top  top  left(0) front(0)  right(0)
    cntrcntrcntr  left(1) front(1)  right(1)
    dwn dwn  dwn  left(2) front(2)  right(2)
    *** near ***          down(0)
    *** cntr ***          down(1)
    *** far  ***          down(2)

      side rubic : color:
    front:B   blue
    up:Y      yellow
    down:W    white
    right:R   red
    left:O    orange
    back:G    green
 */

object Main {
  private def exec_received_steps(step: String, rubic: Rubic_new): Unit = {
//    println(s"exec step $step")
    step match {
      case "F"    => rubic.F_front()
      case "F'"   => rubic.F_back()
      case "F2"   => rubic.F_front_double()
      case "F2'"  => rubic.F_back_double()
      case "U"    => rubic.U_front()
      case "U'"   => rubic.U_back()
      case "U2"   => rubic.U_front_double()
      case "U2'"  => rubic.U_back_double()
      case "D"    => rubic.D_front()
      case "D'"   => rubic.D_back()
      case "D2"   => rubic.D_front_double()
      case "D2'"  => rubic.D_back_double()
      case "R"    => rubic.R_front()
      case "R'"   => rubic.R_back()
      case "R2"   => rubic.R_front_double()
      case "R2'"  => rubic.R_back_double()
      case "L"    => rubic.L_front()
      case "L'"   => rubic.L_back()
      case "L2"   => rubic.L_front_double()
      case "L2'"  => rubic.L_back_double()
      case "B"    => rubic.B_front()
      case "B'"   => rubic.B_back()
      case "B2"   => rubic.B_front_double()
      case "B2'"  => rubic.B_back_double()
    }
//    rubic.show_rubic_color()
  }

  def main(args: Array[String]): Unit = {
    // Create rubic
    val rubic = new Rubic_new
//    rubic.show_rubic_color()
//    rubic.show_rubic_elements()
//    rubic.show_rubic_element_states()

    // Do received movies
    rubic.execSteps(args.head.split(' '))

    // Fix start state
    rubic.fixStartState()

//    rubic.U_back()
//    rubic.show_rubic_color()
//    rubic.show_rubic_elements()
//    rubic.show_rubic_element_states()
//    println("-----COLLECT RUBIC-----")
    rubic.collect_two()
//    rubic.show_rubic_color(true)
//    rubic.show_rubic_elements()
//    rubic.show_rubic_element_states()
    rubic.show_steps()

    // success cases
    // "U L B"
    // "U"
    // "L"
    // "F"
    // "R"
    // "B"
    // "D"
    // "U U"
    // "U L"
    // "U F"
    // "U R"
    // "U B"
    // "U D"
    // "L U"
    // "L L"
    // "L F"
    // "L R"
    // "L B"
    // "L D"
    // "F U"
    // "F L"
    // "F F"
    // "F R"
    // "F B"
    // "F D"
    // "R U"
    // "R L"
    // "R F"
    // "R R"
    // "R B"
    // "R D"
    // "B U"
    // "B L"
    // "B F"
    // "B R"
    // "B B"
    // "B D"
    // "D U"
    // "D L"
    // "D F"
    // "D R"
    // "D B"
    // "D D"

    // failure cases
    "U L F"

    // TESTS
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.U_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.U_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.U_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.F_front()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.R_front()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.B_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.F_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.R_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.L_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.D_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.U_back()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.D_back_double()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.F_back_double()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.L_back_double()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.R_back_double()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.U_back_double()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()
//
//    rubic.B_back_double()
//    rubic.show_rubic_color()
//    println()
//    rubic.show_rubic_elements()
//    println()
//    rubic.show_rubic_element_states()

    // Algorithm
    // 1 этап — сборка правильного креста
    // 2 этап — сборка первого слоя
    // 3 этап — сборка второго слоя
    // 4 этап — сборка креста сверху
    // 5 этап — cборка верхней стороны
    // 6 этап — расстановка ребер
    // 7 этап — перестановка углов
  }
}
