package src

import src.Angle_elem_position.Angle_elem_position
import src.Elem_colors.{Elem_colors, no_color}

class AbstractPositionForAngleElem(up: Elem_colors,
                                   left: Elem_colors,
                                   front: Elem_colors,
                                   right: Elem_colors,
                                   back: Elem_colors,
                                   down: Elem_colors) {
  //--------------------------( 0,    1,     2,     3,    4,    5)
  private val position = Array(up, left, front, right, back, down)

  def getNumberPos(prePosition: String,
                    colorSequence: Array[Elem_colors]): String = {
//    var rr: String = new String
    val allColors = for (color <- position if color != no_color) yield color
//    println(s"Abstract angle pos: ${allColors.mkString(", ")}\n" +
//            s"${colorSequence.mkString(", ")}")
    val indexFirst = colorSequence.indexOf(allColors(0))
    val indexSecond = colorSequence.indexOf(allColors(1))
    val indexThird = colorSequence.indexOf(allColors(2))
    val indexGeneralColor = indexFirst.min(indexSecond.min(indexThird))
    val generalColor = colorSequence(indexGeneralColor)
    val otherTwoColor = position.filter(elem => elem != no_color && elem != generalColor)
//    println(s"Abstract: indexFirst = $indexFirst; 2 = $indexSecond; 3 = $indexThird; genInd = $indexGeneralColor; genColor = $generalColor; other: ${otherTwoColor.mkString}\n" +
//            s"### indexFirst = ${position.indexOf(generalColor)}, sec = ${position.indexOf(otherTwoColor.head)}, last = ${position.indexOf(otherTwoColor.last)}")
//    if (indexGeneralColor < colorSequence.indexOf(otherTwoColor.head) && indexGeneralColor < colorSequence.indexOf(otherTwoColor.last)) {
//      rr = prePosition + 1
//    }
//    else if ((indexGeneralColor < colorSequence.indexOf(otherTwoColor.head) && indexGeneralColor > colorSequence.indexOf(otherTwoColor.last)) ||
//      (indexGeneralColor > colorSequence.indexOf(otherTwoColor.head) && indexGeneralColor < colorSequence.indexOf(otherTwoColor.last))) {
//      rr = prePosition + 2
//    } else {
//      rr = prePosition + 3
//    }
    if (position.indexOf(generalColor) < position.indexOf(otherTwoColor.head) && position.indexOf(generalColor) < position.indexOf(otherTwoColor.last)) {
      prePosition + 1
    }
    else if ((position.indexOf(generalColor) < position.indexOf(otherTwoColor.head) && position.indexOf(generalColor) > position.indexOf(otherTwoColor.last)) ||
      (position.indexOf(generalColor) > position.indexOf(otherTwoColor.head) && position.indexOf(generalColor) < position.indexOf(otherTwoColor.last))) {
      prePosition + 2
    } else {
      prePosition + 3
    }

//    println(s"getNumberPos finish $rr")
//    rr
  }

  def x_front(): Unit = {
    // front -> up
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    position(0) = color_front
    position(1) = color_left
    position(2) = color_down
    position(3) = color_right
    position(4) = color_up
    position(5) = color_back
  }
  def x_back(): Unit = {
    // front -> down
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    position(0) = color_back
    position(1) = color_left
    position(2) = color_up
    position(3) = color_right
    position(4) = color_down
    position(5) = color_front
  }
  def y_front(): Unit = {
    // front -> left
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    position(0) = color_up
    position(1) = color_front
    position(2) = color_right
    position(3) = color_back
    position(4) = color_left
    position(5) = color_down
  }
  def y_back(): Unit = {
    // front -> right
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    position(0) = color_up
    position(1) = color_back
    position(2) = color_left
    position(3) = color_front
    position(4) = color_right
    position(5) = color_down
  }
  def z_front(): Unit = {
    // up -> right
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    position(0) = color_left
    position(1) = color_down
    position(2) = color_front
    position(3) = color_up
    position(4) = color_back
    position(5) = color_right
  }
  def z_back(): Unit = {
    // up -> left
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    position(0) = color_right
    position(1) = color_up
    position(2) = color_front
    position(3) = color_down
    position(4) = color_back
    position(5) = color_left
  }
  def F_front(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 =>
        position(0) = color_left
        position(1) = color_down
        position(2) = color_front
        position(3) = color_up
        position(4) = color_back
        position(5) = color_right
      case _ =>
    }
  }
  def F_back(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 =>
        position(0) = color_right
        position(1) = color_up
        position(2) = color_front
        position(3) = color_down
        position(4) = color_back
        position(5) = color_left
      case _ =>
    }
  }
  def F_front_double(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 =>
        position(0) = color_down
        position(1) = color_right
        position(2) = color_front
        position(3) = color_left
        position(4) = color_back
        position(5) = color_up
      case _ =>
    }
  }
  def F_back_double(currentPos: Angle_elem_position): Unit = F_front_double(currentPos)
  def U_front(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 =>
        position(0) = color_up
        position(1) = color_front
        position(2) = color_right
        position(3) = color_back
        position(4) = color_left
        position(5) = color_down
      case _ =>
    }
  }
  def U_back(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 =>
        position(0) = color_up
        position(1) = color_back
        position(2) = color_left
        position(3) = color_front
        position(4) = color_right
        position(5) = color_down
      case _ =>
    }
  }
  def U_front_double(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 =>
        position(0) = color_up
        position(1) = color_right
        position(2) = color_back
        position(3) = color_left
        position(4) = color_front
        position(5) = color_down
      case _ =>
    }
  }
  def U_back_double(currentPos: Angle_elem_position): Unit = U_front_double(currentPos)
  def D_front(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_up
        position(1) = color_back
        position(2) = color_left
        position(3) = color_front
        position(4) = color_right
        position(5) = color_down
      case _ =>
    }
  }
  def D_back(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_up
        position(1) = color_front
        position(2) = color_right
        position(3) = color_back
        position(4) = color_left
        position(5) = color_down
      case _ =>
    }
  }
  def D_front_double(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_up
        position(1) = color_right
        position(2) = color_back
        position(3) = color_left
        position(4) = color_front
        position(5) = color_down
      case _ =>
    }
  }
  def D_back_double(currentPos: Angle_elem_position): Unit = D_front_double(currentPos)
  def R_front(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 |
           Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 =>
        position(0) = color_front
        position(1) = color_left
        position(2) = color_down
        position(3) = color_right
        position(4) = color_up
        position(5) = color_back
      case _ =>
    }
  }
  def R_back(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 |
           Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 =>
        position(0) = color_back
        position(1) = color_left
        position(2) = color_up
        position(3) = color_right
        position(4) = color_down
        position(5) = color_front
      case _ =>
    }
  }
  def R_front_double(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.fur1 | Angle_elem_position.fur2 | Angle_elem_position.fur3 |
           Angle_elem_position.fdr1 | Angle_elem_position.fdr2 | Angle_elem_position.fdr3 |
           Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 =>
        position(0) = color_down
        position(1) = color_left
        position(2) = color_back
        position(3) = color_right
        position(4) = color_front
        position(5) = color_up
      case _ =>
    }
  }
  def R_back_double(currentPos: Angle_elem_position): Unit = R_front_double(currentPos)
  def L_front(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_back
        position(1) = color_left
        position(2) = color_up
        position(3) = color_right
        position(4) = color_down
        position(5) = color_front
      case _ =>
    }
  }
  def L_back(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_front
        position(1) = color_left
        position(2) = color_down
        position(3) = color_right
        position(4) = color_up
        position(5) = color_back
      case _ =>
    }
  }
  def L_front_double(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.ful1 | Angle_elem_position.ful2 | Angle_elem_position.ful3 |
           Angle_elem_position.fdl1 | Angle_elem_position.fdl2 | Angle_elem_position.fdl3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_down
        position(1) = color_left
        position(2) = color_back
        position(3) = color_right
        position(4) = color_front
        position(5) = color_up
      case _ =>
    }
  }
  def L_back_double(currentPos: Angle_elem_position): Unit = L_front_double(currentPos)
  def B_front(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_right
        position(1) = color_up
        position(2) = color_front
        position(3) = color_down
        position(4) = color_back
        position(5) = color_left
      case _ =>
    }
  }
  def B_back(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_left
        position(1) = color_down
        position(2) = color_front
        position(3) = color_up
        position(4) = color_back
        position(5) = color_right
      case _ =>
    }
  }
  def B_front_double(currentPos: Angle_elem_position): Unit = {
    val color_up = position(0)
    val color_left = position(1)
    val color_front = position(2)
    val color_right = position(3)
    val color_back = position(4)
    val color_down = position(5)

    currentPos match {
      case Angle_elem_position.bul1 | Angle_elem_position.bul2 | Angle_elem_position.bul3 |
           Angle_elem_position.bdl1 | Angle_elem_position.bdl2 | Angle_elem_position.bdl3 |
           Angle_elem_position.bur1 | Angle_elem_position.bur2 | Angle_elem_position.bur3 |
           Angle_elem_position.bdr1 | Angle_elem_position.bdr2 | Angle_elem_position.bdr3 =>
        position(0) = color_down
        position(1) = color_right
        position(2) = color_front
        position(3) = color_left
        position(4) = color_back
        position(5) = color_up
      case _ =>
    }
  }
  def B_back_double(currentPos: Angle_elem_position): Unit = B_front_double(currentPos)
}
