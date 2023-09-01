/*
    Elem angle

      possible positions with color arrangement:
            | a_0   | a_1   | a_2   | a_3   | a_4   | a_5   | a_6   | a_7
    ful:  1 | w|b|o | w|r|b | W-O-G | w|g|r | o|y|g | g|y|r | o|b|y | r|y|b
          2 | o|w|b | b|w|r | g|w|o | r|w|g | g|o|y | r|g|y | y|o|b | b|r|y
          3 | b|o|w | r|b|w | o|g|w | g|r|w | y|g|o | y|r|g | b|y|o | y|b|r
    fur:  1 | w|b|o | w|r|b | w|o|g | W-G-R | o|y|g | g|y|r | o|b|y | r|y|b
          2 | o|w|b | b|w|r | g|w|o | r|w|g | g|o|y | r|g|y | y|o|b | b|r|y
          3 | b|o|w | r|b|w | o|g|w | g|r|w | y|g|o | y|r|g | b|y|o | y|b|r
    fdl:  1 | w|o|b | w|b|r | w|g|o | w|r|g | O-G-Y | g|r|y | o|y|b | r|b|y
          2 | b|w|o | r|w|b | o|w|g | g|w|r | y|o|g | y|g|r | b|o|y | y|r|b
          3 | o|b|w | b|r|w | g|o|w | r|g|w | g|y|o | r|y|g | y|b|o | b|y|r
    fdr:  1 | w|o|b | w|b|r | w|g|o | w|r|g | o|g|y | G-R-Y | o|y|b | r|b|y
          2 | b|w|o | r|w|b | g|o|w | g|w|r | y|o|g | y|g|r | b|o|y | y|r|b
          3 | o|b|w | b|r|w | o|w|g | r|g|w | g|y|o | r|y|g | y|b|o | b|y|r
    bul:  1 | w|b|o | W-R-B | w|o|g | w|g|r | o|y|g | g|y|r | o|b|y | r|y|b
          2 | o|w|b | b|w|r | g|w|o | r|w|g | g|o|y | r|g|y | y|o|b | b|r|y
          3 | b|o|w | r|b|w | o|g|w | g|r|w | y|g|o | y|r|g | b|y|o | y|b|r
    bur:  1 | W-O-B | w|b|r | w|g|o | w|r|g | o|g|y | g|r|y | o|y|b | r|b|y
          2 | b|w|o | r|w|b | o|w|g | g|w|r | y|o|g | y|g|r | b|o|y | y|r|b
          3 | o|b|w | b|r|w | g|o|w | r|g|w | g|y|o | r|y|g | y|b|o | b|y|r
    bdl:  1 | w|o|b | w|b|r | w|g|o | w|r|g | o|g|y | g|r|y | o|y|b | R-B-Y
          2 | b|w|o | r|w|b | o|w|g | g|w|r | y|o|g | y|g|r | b|o|y | y|r|b
          3 | o|b|w | b|r|w | g|o|w | r|g|w | g|y|o | r|y|g | y|b|o | b|y|r
    bdr:  1 | w|b|o | w|r|b | w|o|g | w|g|r | o|y|g | g|y|r | O-B-Y | r|y|b
          2 | o|w|b | b|w|r | g|w|o | r|w|g | g|o|y | r|g|y | y|o|b | b|r|y
          3 | b|o|w | r|b|w | o|g|w | g|r|w | y|g|o | y|r|g | b|y|o | y|b|r
 */

package src

import src.Angle_elem_position._
import src.Elem_angle.colors_map_a
import src.Elem_colors._
import src.Side_position._

class Elem_angle(name: String,
                 color_1: Elem_colors,
                 val color_2: Elem_colors,
                 val color_3: Elem_colors,
                 var target_pos: Angle_elem_position,
                 var current_pos: Angle_elem_position,
                 val abstract_pos: AbstractPositionForAngleElem)
  extends Elem(name, color_1) {

  def get_color(side: Side_position): Char = {
    current_pos match {
        case Angle_elem_position.ful1 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.left => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.ful2 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.left => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.ful3 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.left => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.fur1 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.fur2 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.fur3 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.fdl1 => {
          side match {
            case Side_position.left => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.fdl2 => {
          side match {
            case Side_position.left => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.fdl3 => {
          side match {
            case Side_position.left => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.front => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.fdr1 => {
          side match {
            case Side_position.front => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.fdr2 => {
          side match {
            case Side_position.front => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.fdr3 => {
          side match {
            case Side_position.front => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.bul1 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.bul2 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.bul3 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.right => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.bur1 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.left => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.bur2 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.left => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.bur3 => {
          side match {
            case Side_position.up => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.left => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.bdl1 => {
          side match {
            case Side_position.right => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.bdl2 => {
          side match {
            case Side_position.right => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.bdl3 => {
          side match {
            case Side_position.right => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
        case Angle_elem_position.bdr1 => {
          side match {
            case Side_position.left => colors_map_a(name)(current_pos.toString)(0) // color_1.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(1) // color_2.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_3.toString.head
          }
        }
        case Angle_elem_position.bdr2 => {
          side match {
            case Side_position.left => colors_map_a(name)(current_pos.toString)(0) // color_3.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(1) // color_1.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_2.toString.head
          }
        }
        case Angle_elem_position.bdr3 => {
          side match {
            case Side_position.left => colors_map_a(name)(current_pos.toString)(0) // color_2.toString.head
            case Side_position.back => colors_map_a(name)(current_pos.toString)(1) // color_3.toString.head
            case Side_position.down => colors_map_a(name)(current_pos.toString)(2) // color_1.toString.head
          }
        }
    }
  }
  def getName: String = name
  def getCurrentPos: Angle_elem_position = current_pos
  def getTargetPos: Angle_elem_position = target_pos
  def getElemState: Angle_elem_position = current_pos
  def checkComplete: Boolean = if (target_pos == current_pos) true else false
  private def convertStringToElemPosition(str: String): Angle_elem_position = {
    str match {
      case "ful1" => ful1
      case "ful2" => ful2
      case "ful3" => ful3
      case "fur1" => fur1
      case "fur2" => fur2
      case "fur3" => fur3
      case "fdl1" => fdl1
      case "fdl2" => fdl2
      case "fdl3" => fdl3
      case "fdr1" => fdr1
      case "fdr2" => fdr2
      case "fdr3" => fdr3
      case "bul1" => bul1
      case "bul2" => bul2
      case "bul3" => bul3
      case "bur1" => bur1
      case "bur2" => bur2
      case "bur3" => bur3
      case "bdl1" => bdl1
      case "bdl2" => bdl2
      case "bdl3" => bdl3
      case "bdr1" => bdr1
      case "bdr2" => bdr2
      case "bdr3" => bdr3
    }
  }
  private def changePosition(colorSequence: Array[Elem_colors],
                             startState: Angle_elem_position): Angle_elem_position = {
    convertStringToElemPosition(abstract_pos.getNumberPos(startState.toString.substring(0, 3), colorSequence))
  }

  def x_front(colorSequence: Array[Elem_colors]): Unit = {
    // front -> up
    abstract_pos.x_front()
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = if (checkComplete) bur1 else changePosition(colorSequence, bur1)//bur1
      case Angle_elem_position.ful2 => current_pos = changePosition(colorSequence, bur1)//bur3
      case Angle_elem_position.ful3 => current_pos = changePosition(colorSequence, bur1)//bur2
      case Angle_elem_position.fur1 => current_pos = if (checkComplete) bul1 else changePosition(colorSequence, bul1)// bul1//
      case Angle_elem_position.fur2 => current_pos = changePosition(colorSequence, bul1)//bul2
      case Angle_elem_position.fur3 => current_pos = changePosition(colorSequence, bul1)//bul3
      case Angle_elem_position.fdl1 => current_pos = if (checkComplete) ful1 else changePosition(colorSequence, ful1)// ful1//
      case Angle_elem_position.fdl2 => current_pos = changePosition(colorSequence, ful1)//ful3
      case Angle_elem_position.fdl3 => current_pos = changePosition(colorSequence, ful1)//ful2
      case Angle_elem_position.fdr1 => current_pos = if (checkComplete) fur1 else changePosition(colorSequence, fur1)// fur1//
      case Angle_elem_position.fdr2 => current_pos = changePosition(colorSequence, fur1)//fur3
      case Angle_elem_position.fdr3 => current_pos = changePosition(colorSequence, fur1)//fur2
      case Angle_elem_position.bul1 => current_pos = if (checkComplete) bdl1 else changePosition(colorSequence, bdl1)// bdl1//
      case Angle_elem_position.bul2 => current_pos = changePosition(colorSequence, bdl1)//bdl3
      case Angle_elem_position.bul3 => current_pos = changePosition(colorSequence, bdl1)//bdl2
      case Angle_elem_position.bur1 => current_pos = if (checkComplete) bdr1 else changePosition(colorSequence, bdr1)// bdr1//
      case Angle_elem_position.bur2 => current_pos = changePosition(colorSequence, bdr1)//bdr3
      case Angle_elem_position.bur3 => current_pos = changePosition(colorSequence, bdr1)//bdr2
      case Angle_elem_position.bdl1 => current_pos = if (checkComplete) fdr1 else changePosition(colorSequence, fdr1)// fdr1//
      case Angle_elem_position.bdl2 => current_pos = changePosition(colorSequence, fdr1)//fdr2
      case Angle_elem_position.bdl3 => current_pos = changePosition(colorSequence, fdr1)//fdr3
      case Angle_elem_position.bdr1 => current_pos = if (checkComplete) fdl1 else changePosition(colorSequence, fdl1)// fdl1//
      case Angle_elem_position.bdr2 => current_pos = changePosition(colorSequence, fdl1)//fdl3
      case Angle_elem_position.bdr3 => current_pos = changePosition(colorSequence, fdl1)//fdl2
    }
    target_pos match {
      case Angle_elem_position.ful1 => target_pos = bur1
      case Angle_elem_position.fur1 => target_pos = bul1
      case Angle_elem_position.fdl1 => target_pos = ful1
      case Angle_elem_position.fdr1 => target_pos = fur1
      case Angle_elem_position.bul1 => target_pos = bdl1
      case Angle_elem_position.bur1 => target_pos = bdr1
      case Angle_elem_position.bdl1 => target_pos = fdr1
      case Angle_elem_position.bdr1 => target_pos = fdl1
    }
  }
  def x_back(colorSequence: Array[Elem_colors]): Unit = {
    // front -> down
    abstract_pos.x_back()
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = if (checkComplete) fdl1 else changePosition(colorSequence, fdl1)//fdl1//
      case Angle_elem_position.ful2 => current_pos = changePosition(colorSequence, fdl1)//fdl3
      case Angle_elem_position.ful3 => current_pos = changePosition(colorSequence, fdl1)//fdl2
      case Angle_elem_position.fur1 => current_pos = if (checkComplete) fdr1 else changePosition(colorSequence, fdr1)//fdr1//
      case Angle_elem_position.fur2 => current_pos = changePosition(colorSequence, fdr1)//fdr3
      case Angle_elem_position.fur3 => current_pos = changePosition(colorSequence, fdr1)//fdr2
      case Angle_elem_position.fdl1 => current_pos = if (checkComplete) bdr1 else changePosition(colorSequence, bdr1)//bdr1//
      case Angle_elem_position.fdl2 => current_pos = changePosition(colorSequence, bdr1)//bdr3
      case Angle_elem_position.fdl3 => current_pos = changePosition(colorSequence, bdr1)//bdr2
      case Angle_elem_position.fdr1 => current_pos = if (checkComplete) bdl1 else changePosition(colorSequence, bdl1)//bdl1//
      case Angle_elem_position.fdr2 => current_pos = changePosition(colorSequence, bdl1)//bdl2
      case Angle_elem_position.fdr3 => current_pos = changePosition(colorSequence, bdl1)//bdl3
      case Angle_elem_position.bul1 => current_pos = if (checkComplete) fur1 else changePosition(colorSequence, fur1)//fur1//
      case Angle_elem_position.bul2 => current_pos = changePosition(colorSequence, fur1)//fur2
      case Angle_elem_position.bul3 => current_pos = changePosition(colorSequence, fur1)//fur3
      case Angle_elem_position.bur1 => current_pos = if (checkComplete) ful1 else changePosition(colorSequence, ful1)//ful1//
      case Angle_elem_position.bur2 => current_pos = changePosition(colorSequence, ful1)//ful3
      case Angle_elem_position.bur3 => current_pos = changePosition(colorSequence, ful1)//ful2
      case Angle_elem_position.bdl1 => current_pos = if (checkComplete) bul1 else changePosition(colorSequence, bul1)//bul1//
      case Angle_elem_position.bdl2 => current_pos = changePosition(colorSequence, bul1)//bul3
      case Angle_elem_position.bdl3 => current_pos = changePosition(colorSequence, bul1)//bul2
      case Angle_elem_position.bdr1 => current_pos = if (checkComplete) bur1 else changePosition(colorSequence, bur1)//bur1//
      case Angle_elem_position.bdr2 => current_pos = changePosition(colorSequence, bur1)//bur3
      case Angle_elem_position.bdr3 => current_pos = changePosition(colorSequence, bur1)//bur2
    }
    target_pos match {
      case Angle_elem_position.ful1 => target_pos = fdl1
      case Angle_elem_position.fur1 => target_pos = fdr1
      case Angle_elem_position.fdl1 => target_pos = bdr1
      case Angle_elem_position.fdr1 => target_pos = bdl1
      case Angle_elem_position.bul1 => target_pos = fur1
      case Angle_elem_position.bur1 => target_pos = ful1
      case Angle_elem_position.bdl1 => target_pos = bul1
      case Angle_elem_position.bdr1 => target_pos = bur1
    }
  }
  def y_front(colorSequence: Array[Elem_colors]): Unit = {
    // front -> left
    abstract_pos.y_front()
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = if (checkComplete) bur1 else changePosition(colorSequence, bur1)//bur1//
      case Angle_elem_position.ful2 => current_pos = changePosition(colorSequence, bur1)//bur3
      case Angle_elem_position.ful3 => current_pos = changePosition(colorSequence, bur1)//bur2
      case Angle_elem_position.fur1 => current_pos = if (checkComplete) ful1 else changePosition(colorSequence, ful1)//ful1//
      case Angle_elem_position.fur2 => current_pos = changePosition(colorSequence, ful1)//ful2
      case Angle_elem_position.fur3 => current_pos = changePosition(colorSequence, ful1)//ful3
      case Angle_elem_position.fdl1 => current_pos = if (checkComplete) bdr1 else changePosition(colorSequence, bdr1)//bdr1//
      case Angle_elem_position.fdl2 => current_pos = changePosition(colorSequence, bdr1)//bdr3
      case Angle_elem_position.fdl3 => current_pos = changePosition(colorSequence, bdr1)//bdr2
      case Angle_elem_position.fdr1 => current_pos = if (checkComplete) fdl1 else changePosition(colorSequence, fdl1)//fdl1//
      case Angle_elem_position.fdr2 => current_pos = changePosition(colorSequence, fdl1)//fdl2
      case Angle_elem_position.fdr3 => current_pos = changePosition(colorSequence, fdl1)//fdl3
      case Angle_elem_position.bul1 => current_pos = if (checkComplete) fur1 else changePosition(colorSequence, fur1)//fur1//
      case Angle_elem_position.bul2 => current_pos = changePosition(colorSequence, fur1)//fur2
      case Angle_elem_position.bul3 => current_pos = changePosition(colorSequence, fur1)//fur3
      case Angle_elem_position.bur1 => current_pos = if (checkComplete) bul1 else changePosition(colorSequence, bul1)//bul1//
      case Angle_elem_position.bur2 => current_pos = changePosition(colorSequence, bul1)//bul3
      case Angle_elem_position.bur3 => current_pos = changePosition(colorSequence, bul1)//bul2
      case Angle_elem_position.bdl1 => current_pos = if (checkComplete) fdr1 else changePosition(colorSequence, fdr1)//fdr1//
      case Angle_elem_position.bdl2 => current_pos = changePosition(colorSequence, fdr1)//fdr2
      case Angle_elem_position.bdl3 => current_pos = changePosition(colorSequence, fdr1)//fdr3
      case Angle_elem_position.bdr1 => current_pos = if (checkComplete) bdl1 else changePosition(colorSequence, bdl1)//bdl1//
      case Angle_elem_position.bdr2 => current_pos = changePosition(colorSequence, bdl1)//bdl3
      case Angle_elem_position.bdr3 => current_pos = changePosition(colorSequence, bdl1)//bdl2
    }
    target_pos match {
      case Angle_elem_position.ful1 => target_pos = bur1
      case Angle_elem_position.fur1 => target_pos = ful1
      case Angle_elem_position.fdl1 => target_pos = bdr1
      case Angle_elem_position.fdr1 => target_pos = fdl1
      case Angle_elem_position.bul1 => target_pos = fur1
      case Angle_elem_position.bur1 => target_pos = bul1
      case Angle_elem_position.bdl1 => target_pos = fdr1
      case Angle_elem_position.bdr1 => target_pos = bdl1
    }
  }
  def y_back(colorSequence: Array[Elem_colors]): Unit = {
    // front -> right
    abstract_pos.y_back()
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = if (checkComplete) fur1 else changePosition(colorSequence, fur1)//fur1//
      case Angle_elem_position.ful2 => current_pos = changePosition(colorSequence, fur1)//fur2
      case Angle_elem_position.ful3 => current_pos = changePosition(colorSequence, fur1)//fur3
      case Angle_elem_position.fur1 => current_pos = if (checkComplete) bul1 else changePosition(colorSequence, bul1)//bul1//
      case Angle_elem_position.fur2 => current_pos = changePosition(colorSequence, bul1)//bul2
      case Angle_elem_position.fur3 => current_pos = changePosition(colorSequence, bul1)//bul3
      case Angle_elem_position.fdl1 => current_pos = if (checkComplete) fdr1 else changePosition(colorSequence, fdr1)//fdr1//
      case Angle_elem_position.fdl2 => current_pos = changePosition(colorSequence, fdr1)//fdr2
      case Angle_elem_position.fdl3 => current_pos = changePosition(colorSequence, fdr1)//fdr3
      case Angle_elem_position.fdr1 => current_pos = if (checkComplete) bdl1 else changePosition(colorSequence, bdl1)//bdl1//
      case Angle_elem_position.fdr2 => current_pos = changePosition(colorSequence, bdl1)//bdl2
      case Angle_elem_position.fdr3 => current_pos = changePosition(colorSequence, bdl1)//bdl3
      case Angle_elem_position.bul1 => current_pos = if (checkComplete) bur1 else changePosition(colorSequence, bur1)//bur1//
      case Angle_elem_position.bul2 => current_pos = changePosition(colorSequence, bur1)//bur3
      case Angle_elem_position.bul3 => current_pos = changePosition(colorSequence, bur1)//bur2
      case Angle_elem_position.bur1 => current_pos = if (checkComplete) ful1 else changePosition(colorSequence, ful1)//ful1//
      case Angle_elem_position.bur2 => current_pos = changePosition(colorSequence, ful1)//ful3
      case Angle_elem_position.bur3 => current_pos = changePosition(colorSequence, ful1)//ful2
      case Angle_elem_position.bdl1 => current_pos = if (checkComplete) bdr1 else changePosition(colorSequence, bdr1)//bdr1//
      case Angle_elem_position.bdl2 => current_pos = changePosition(colorSequence, bdr1)//bdr3
      case Angle_elem_position.bdl3 => current_pos = changePosition(colorSequence, bdr1)//bdr2
      case Angle_elem_position.bdr1 => current_pos = if (checkComplete) fdl1 else changePosition(colorSequence, fdl1)//fdl1//
      case Angle_elem_position.bdr2 => current_pos = changePosition(colorSequence, fdl1)//fdl3
      case Angle_elem_position.bdr3 => current_pos = changePosition(colorSequence, fdl1)//fdl2
    }
    target_pos match {
      case Angle_elem_position.ful1 => target_pos = fur1
      case Angle_elem_position.fur1 => target_pos = bul1
      case Angle_elem_position.fdl1 => target_pos = fdr1
      case Angle_elem_position.fdr1 => target_pos = bdl1
      case Angle_elem_position.bul1 => target_pos = bur1
      case Angle_elem_position.bur1 => target_pos = ful1
      case Angle_elem_position.bdl1 => target_pos = bdr1
      case Angle_elem_position.bdr1 => target_pos = fdl1
    }
  }
  def z_front(colorSequence: Array[Elem_colors]): Unit = {
    // up -> right
    abstract_pos.z_front()
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = if (checkComplete) fur1 else changePosition(colorSequence, fur1)//fur1//
      case Angle_elem_position.ful2 => current_pos = changePosition(colorSequence, fur1)//fur2
      case Angle_elem_position.ful3 => current_pos = changePosition(colorSequence, fur1)//fur3
      case Angle_elem_position.fur1 => current_pos = if (checkComplete) fdr1 else changePosition(colorSequence, fdr1)//fdr1//
      case Angle_elem_position.fur2 => current_pos = changePosition(colorSequence, fdr1)//fdr3
      case Angle_elem_position.fur3 => current_pos = changePosition(colorSequence, fdr1)//fdr2
      case Angle_elem_position.fdl1 => current_pos = if (checkComplete) ful1 else changePosition(colorSequence, ful1)//ful1//
      case Angle_elem_position.fdl2 => current_pos = changePosition(colorSequence, ful1)//ful3
      case Angle_elem_position.fdl3 => current_pos = changePosition(colorSequence, ful1)//ful2
      case Angle_elem_position.fdr1 => current_pos = if (checkComplete) fdl1 else changePosition(colorSequence, fdl1)//fdl1//
      case Angle_elem_position.fdr2 => current_pos = changePosition(colorSequence, fdl1)//fdl2
      case Angle_elem_position.fdr3 => current_pos = changePosition(colorSequence, fdl1)//fdr3
      case Angle_elem_position.bul1 => current_pos = if (checkComplete) bdl1 else changePosition(colorSequence, bdl1)//bdl1//
      case Angle_elem_position.bul2 => current_pos = changePosition(colorSequence, bdl1)//bdl3
      case Angle_elem_position.bul3 => current_pos = changePosition(colorSequence, bdl1)//bdl2
      case Angle_elem_position.bur1 => current_pos = if (checkComplete) bul1 else changePosition(colorSequence, bul1)//bul1//
      case Angle_elem_position.bur2 => current_pos = changePosition(colorSequence, bul1)//bul3
      case Angle_elem_position.bur3 => current_pos = changePosition(colorSequence, bul1)//bul2
      case Angle_elem_position.bdl1 => current_pos = if (checkComplete) bdr1 else changePosition(colorSequence, bdr1)//bdr1//
      case Angle_elem_position.bdl2 => current_pos = changePosition(colorSequence, bdr1)//bdr3
      case Angle_elem_position.bdl3 => current_pos = changePosition(colorSequence, bdr1)//bdr2
      case Angle_elem_position.bdr1 => current_pos = if (checkComplete) bur1 else changePosition(colorSequence, bur1)//bur1//
      case Angle_elem_position.bdr2 => current_pos = changePosition(colorSequence, bur1)//bur3
      case Angle_elem_position.bdr3 => current_pos = changePosition(colorSequence, bur1)//bur2
    }
    target_pos match {
      case Angle_elem_position.ful1 => target_pos = fur1
      case Angle_elem_position.fur1 => target_pos = fdr1
      case Angle_elem_position.fdl1 => target_pos = ful1
      case Angle_elem_position.fdr1 => target_pos = fdl1
      case Angle_elem_position.bul1 => target_pos = bdl1
      case Angle_elem_position.bur1 => target_pos = bul1
      case Angle_elem_position.bdl1 => target_pos = bdr1
      case Angle_elem_position.bdr1 => target_pos = bur1
    }
  }
  def z_back(colorSequence: Array[Elem_colors]): Unit = {
    // up -> left
    abstract_pos.z_back()
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = if (checkComplete) fdl1 else changePosition(colorSequence, fdl1)//fdl1//
      case Angle_elem_position.ful2 => current_pos = changePosition(colorSequence, fdl1)//fdl3
      case Angle_elem_position.ful3 => current_pos = changePosition(colorSequence, fdl1)//fdl2
      case Angle_elem_position.fur1 => current_pos = if (checkComplete) ful1 else changePosition(colorSequence, ful1)//ful1//
      case Angle_elem_position.fur2 => current_pos = changePosition(colorSequence, ful1)//ful2
      case Angle_elem_position.fur3 => current_pos = changePosition(colorSequence, ful1)//ful3
      case Angle_elem_position.fdl1 => current_pos = if (checkComplete) fdr1 else changePosition(colorSequence, fdr1)//fdr1//
      case Angle_elem_position.fdl2 => current_pos = changePosition(colorSequence, fdr1)//fdr2
      case Angle_elem_position.fdl3 => current_pos = changePosition(colorSequence, fdr1)//fdr3
      case Angle_elem_position.fdr1 => current_pos = if (checkComplete) fur1 else changePosition(colorSequence, fur1)//fur1//
      case Angle_elem_position.fdr2 => current_pos = changePosition(colorSequence, fur1)//fur3
      case Angle_elem_position.fdr3 => current_pos = changePosition(colorSequence, fur1)//fur2
      case Angle_elem_position.bul1 => current_pos = if (checkComplete) bur1 else changePosition(colorSequence, bur1)//bur1//
      case Angle_elem_position.bul2 => current_pos = changePosition(colorSequence, bur1)//bur3
      case Angle_elem_position.bul3 => current_pos = changePosition(colorSequence, bur1)//bur2
      case Angle_elem_position.bur1 => current_pos = if (checkComplete) bdr1 else changePosition(colorSequence, bdr1)//bdr1//
      case Angle_elem_position.bur2 => current_pos = changePosition(colorSequence, bdr1)//bdr3
      case Angle_elem_position.bur3 => current_pos = changePosition(colorSequence, bdr1)//bdr2
      case Angle_elem_position.bdl1 => current_pos = if (checkComplete) bul1 else changePosition(colorSequence, bul1)//bul1//
      case Angle_elem_position.bdl2 => current_pos = changePosition(colorSequence, bul1)//bul3
      case Angle_elem_position.bdl3 => current_pos = changePosition(colorSequence, bul1)//bul2
      case Angle_elem_position.bdr1 => current_pos = if (checkComplete) bdl1 else changePosition(colorSequence, bdl1)//bdl1//
      case Angle_elem_position.bdr2 => current_pos = changePosition(colorSequence, bdl1)//bdl2
      case Angle_elem_position.bdr3 => current_pos = changePosition(colorSequence, bdl1)//bdl3
    }
    target_pos match {
      case Angle_elem_position.ful1 => target_pos = fdl1
      case Angle_elem_position.fur1 => target_pos = ful1
      case Angle_elem_position.fdl1 => target_pos = fdr1
      case Angle_elem_position.fdr1 => target_pos = fur1
      case Angle_elem_position.bul1 => target_pos = bur1
      case Angle_elem_position.bur1 => target_pos = bdr1
      case Angle_elem_position.bdl1 => target_pos = bul1
      case Angle_elem_position.bdr1 => target_pos = bdl1
    }
  }
  def F_front(): Unit = {
    abstract_pos.F_front(current_pos)
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = fur3
      case Angle_elem_position.ful2 => current_pos = fur1
      case Angle_elem_position.ful3 => current_pos = fur2
      case Angle_elem_position.fur1 => current_pos = fdr2
      case Angle_elem_position.fur2 => current_pos = fdr1
      case Angle_elem_position.fur3 => current_pos = fdr3
      case Angle_elem_position.fdl1 => current_pos = ful1
      case Angle_elem_position.fdl2 => current_pos = ful3
      case Angle_elem_position.fdl3 => current_pos = ful2
      case Angle_elem_position.fdr1 => current_pos = fdl2
      case Angle_elem_position.fdr2 => current_pos = fdl3
      case Angle_elem_position.fdr3 => current_pos = fdl1
    }
  }
  def F_back(): Unit = {
    abstract_pos.F_back(current_pos)
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = fdl1
      case Angle_elem_position.ful2 => current_pos = fdl3
      case Angle_elem_position.ful3 => current_pos = fdl2
      case Angle_elem_position.fur1 => current_pos = ful2
      case Angle_elem_position.fur2 => current_pos = ful3
      case Angle_elem_position.fur3 => current_pos = ful1
      case Angle_elem_position.fdl1 => current_pos = fdr3
      case Angle_elem_position.fdl2 => current_pos = fdr1
      case Angle_elem_position.fdl3 => current_pos = fdr2
      case Angle_elem_position.fdr1 => current_pos = fur2
      case Angle_elem_position.fdr2 => current_pos = fur1
      case Angle_elem_position.fdr3 => current_pos = fur3
    }
  }
  def F_front_double(): Unit = {
    abstract_pos.F_front_double(current_pos)
    current_pos match {
      case Angle_elem_position.ful1 => current_pos = fdr3
      case Angle_elem_position.ful2 => current_pos = fdr2
      case Angle_elem_position.ful3 => current_pos = fdr1
      case Angle_elem_position.fur1 => current_pos = fdl3
      case Angle_elem_position.fur2 => current_pos = fdl2
      case Angle_elem_position.fur3 => current_pos = fdl1
      case Angle_elem_position.fdl1 => current_pos = fur3
      case Angle_elem_position.fdl2 => current_pos = fur2
      case Angle_elem_position.fdl3 => current_pos = fur1
      case Angle_elem_position.fdr1 => current_pos = ful3
      case Angle_elem_position.fdr2 => current_pos = ful2
      case Angle_elem_position.fdr3 => current_pos = ful1
    }
  }
  def F_back_double(): Unit = F_front_double()
  def U_front(): Unit = {
    abstract_pos.U_front(current_pos)
    current_pos match {
      case Angle_elem_position.bur1 => current_pos = bul1
      case Angle_elem_position.bur2 => current_pos = bul3
      case Angle_elem_position.bur3 => current_pos = bul2
      case Angle_elem_position.bul1 => current_pos = fur1
      case Angle_elem_position.bul2 => current_pos = fur2
      case Angle_elem_position.bul3 => current_pos = fur3
      case Angle_elem_position.ful1 => current_pos = bur1
      case Angle_elem_position.ful2 => current_pos = bur3
      case Angle_elem_position.ful3 => current_pos = bur2
      case Angle_elem_position.fur1 => current_pos = ful1
      case Angle_elem_position.fur2 => current_pos = ful2
      case Angle_elem_position.fur3 => current_pos = ful3
    }
  }
  def U_back(): Unit = {
    abstract_pos.U_back(current_pos)
    current_pos match {
      case Angle_elem_position.bur1 => current_pos = ful1
      case Angle_elem_position.bur2 => current_pos = ful3
      case Angle_elem_position.bur3 => current_pos = ful2
      case Angle_elem_position.bul1 => current_pos = bur1
      case Angle_elem_position.bul2 => current_pos = bur3
      case Angle_elem_position.bul3 => current_pos = bur2
      case Angle_elem_position.ful1 => current_pos = fur1
      case Angle_elem_position.ful2 => current_pos = fur2
      case Angle_elem_position.ful3 => current_pos = fur3
      case Angle_elem_position.fur1 => current_pos = bul1
      case Angle_elem_position.fur2 => current_pos = bul2
      case Angle_elem_position.fur3 => current_pos = bul3
    }
  }
  def U_front_double(): Unit = {
    abstract_pos.U_front_double(current_pos)
    current_pos match {
      case Angle_elem_position.bur1 => current_pos = fur1
      case Angle_elem_position.bur2 => current_pos = fur3
      case Angle_elem_position.bur3 => current_pos = fur2
      case Angle_elem_position.bul1 => current_pos = ful1
      case Angle_elem_position.bul2 => current_pos = ful2
      case Angle_elem_position.bul3 => current_pos = ful3
      case Angle_elem_position.ful1 => current_pos = bul1
      case Angle_elem_position.ful2 => current_pos = bul2
      case Angle_elem_position.ful3 => current_pos = bul3
      case Angle_elem_position.fur1 => current_pos = bur1
      case Angle_elem_position.fur2 => current_pos = bur3
      case Angle_elem_position.fur3 => current_pos = bur2
    }
  }
  def U_back_double(): Unit = U_front_double()
  def D_front(): Unit = {
    abstract_pos.D_front(current_pos)
    current_pos match {
      case Angle_elem_position.fdl1 => current_pos = fdr1
      case Angle_elem_position.fdl2 => current_pos = fdr2
      case Angle_elem_position.fdl3 => current_pos = fdr3
      case Angle_elem_position.fdr1 => current_pos = bdl1
      case Angle_elem_position.fdr2 => current_pos = bdl2
      case Angle_elem_position.fdr3 => current_pos = bdl3
      case Angle_elem_position.bdr1 => current_pos = fdl2
      case Angle_elem_position.bdr2 => current_pos = fdl1
      case Angle_elem_position.bdr3 => current_pos = fdl3
      case Angle_elem_position.bdl1 => current_pos = bdr2
      case Angle_elem_position.bdl2 => current_pos = bdr1
      case Angle_elem_position.bdl3 => current_pos = bdr3
    }
  }
  def D_back(): Unit = {
    abstract_pos.D_back(current_pos)
    current_pos match {
      case Angle_elem_position.fdl1 => current_pos = bdr2
      case Angle_elem_position.fdl2 => current_pos = bdr1
      case Angle_elem_position.fdl3 => current_pos = bdr3
      case Angle_elem_position.fdr1 => current_pos = fdl1
      case Angle_elem_position.fdr2 => current_pos = fdl2
      case Angle_elem_position.fdr3 => current_pos = fdl3
      case Angle_elem_position.bdr1 => current_pos = bdl2
      case Angle_elem_position.bdr2 => current_pos = bdl1
      case Angle_elem_position.bdr3 => current_pos = bdl3
      case Angle_elem_position.bdl1 => current_pos = fdr1
      case Angle_elem_position.bdl2 => current_pos = fdr2
      case Angle_elem_position.bdl3 => current_pos = fdr3
    }
  }
  def D_front_double(): Unit = {
    abstract_pos.D_front_double(current_pos)
    current_pos match {
      case Angle_elem_position.fdl1 => current_pos = bdl1
      case Angle_elem_position.fdl2 => current_pos = bdl2
      case Angle_elem_position.fdl3 => current_pos = bdl3
      case Angle_elem_position.fdr1 => current_pos = bdr2
      case Angle_elem_position.fdr2 => current_pos = bdr1
      case Angle_elem_position.fdr3 => current_pos = bdr3
      case Angle_elem_position.bdr1 => current_pos = fdr2
      case Angle_elem_position.bdr2 => current_pos = fdr1
      case Angle_elem_position.bdr3 => current_pos = fdr3
      case Angle_elem_position.bdl1 => current_pos = fdl1
      case Angle_elem_position.bdl2 => current_pos = fdl2
      case Angle_elem_position.bdl3 => current_pos = fdl3
    }
  }
  def D_back_double(): Unit = D_front_double()
  def R_front(): Unit = {
    abstract_pos.R_front(current_pos)
    current_pos match {
      case Angle_elem_position.fur1 => current_pos = bul3
      case Angle_elem_position.fur2 => current_pos = bul1
      case Angle_elem_position.fur3 => current_pos = bul2
      case Angle_elem_position.bul1 => current_pos = bdl2
      case Angle_elem_position.bul2 => current_pos = bdl1
      case Angle_elem_position.bul3 => current_pos = bdl3
      case Angle_elem_position.fdr1 => current_pos = fur1
      case Angle_elem_position.fdr2 => current_pos = fur3
      case Angle_elem_position.fdr3 => current_pos = fur2
      case Angle_elem_position.bdl1 => current_pos = fdr2
      case Angle_elem_position.bdl2 => current_pos = fdr3
      case Angle_elem_position.bdl3 => current_pos = fdr1
    }
  }
  def R_back(): Unit = {
    abstract_pos.R_back(current_pos)
    current_pos match {
      case Angle_elem_position.fur1 => current_pos = fdr1
      case Angle_elem_position.fur2 => current_pos = fdr3
      case Angle_elem_position.fur3 => current_pos = fdr2
      case Angle_elem_position.bul1 => current_pos = fur2
      case Angle_elem_position.bul2 => current_pos = fur3
      case Angle_elem_position.bul3 => current_pos = fur1
      case Angle_elem_position.fdr1 => current_pos = bdl3
      case Angle_elem_position.fdr2 => current_pos = bdl1
      case Angle_elem_position.fdr3 => current_pos = bdl2
      case Angle_elem_position.bdl1 => current_pos = bul2
      case Angle_elem_position.bdl2 => current_pos = bul1
      case Angle_elem_position.bdl3 => current_pos = bul3
    }
  }
  def R_front_double(): Unit = {
    abstract_pos.R_front_double(current_pos)
    current_pos match {
      case Angle_elem_position.fur1 => current_pos = bdl3
      case Angle_elem_position.fur2 => current_pos = bdl2
      case Angle_elem_position.fur3 => current_pos = bdl1
      case Angle_elem_position.bul1 => current_pos = fdr3
      case Angle_elem_position.bul2 => current_pos = fdr2
      case Angle_elem_position.bul3 => current_pos = fdr1
      case Angle_elem_position.fdr1 => current_pos = bul3
      case Angle_elem_position.fdr2 => current_pos = bul2
      case Angle_elem_position.fdr3 => current_pos = bul1
      case Angle_elem_position.bdl1 => current_pos = fur3
      case Angle_elem_position.bdl2 => current_pos = fur2
      case Angle_elem_position.bdl3 => current_pos = fur1
    }
  }
  def R_back_double(): Unit = R_front_double()
  def L_front(): Unit = {
    abstract_pos.L_front(current_pos)
    current_pos match {
      case Angle_elem_position.bur1 => current_pos = ful3
      case Angle_elem_position.bur2 => current_pos = ful2
      case Angle_elem_position.bur3 => current_pos = ful1
      case Angle_elem_position.ful1 => current_pos = fdl2
      case Angle_elem_position.ful2 => current_pos = fdl1
      case Angle_elem_position.ful3 => current_pos = fdl3
      case Angle_elem_position.bdr1 => current_pos = bur2
      case Angle_elem_position.bdr2 => current_pos = bur1
      case Angle_elem_position.bdr3 => current_pos = bur3
      case Angle_elem_position.fdl1 => current_pos = bdr1
      case Angle_elem_position.fdl2 => current_pos = bdr3
      case Angle_elem_position.fdl3 => current_pos = bdr2
    }
  }
  def L_back(): Unit = {
    abstract_pos.L_back(current_pos)
    current_pos match {
      case Angle_elem_position.bur1 => current_pos = bdr2
      case Angle_elem_position.bur2 => current_pos = bdr1
      case Angle_elem_position.bur3 => current_pos = bdr3
      case Angle_elem_position.ful1 => current_pos = bur3
      case Angle_elem_position.ful2 => current_pos = bur2
      case Angle_elem_position.ful3 => current_pos = bur1
      case Angle_elem_position.bdr1 => current_pos = fdl1
      case Angle_elem_position.bdr2 => current_pos = fdl3
      case Angle_elem_position.bdr3 => current_pos = fdl2
      case Angle_elem_position.fdl1 => current_pos = ful2
      case Angle_elem_position.fdl2 => current_pos = ful1
      case Angle_elem_position.fdl3 => current_pos = ful3
    }
  }
  def L_front_double(): Unit = {
    abstract_pos.L_front_double(current_pos)
    current_pos match {
      case Angle_elem_position.bur1 => current_pos = fdl3
      case Angle_elem_position.bur2 => current_pos = fdl1
      case Angle_elem_position.bur3 => current_pos = fdl2
      case Angle_elem_position.ful1 => current_pos = bdr3
      case Angle_elem_position.ful2 => current_pos = bdr1
      case Angle_elem_position.ful3 => current_pos = bdr2
      case Angle_elem_position.bdr1 => current_pos = ful2
      case Angle_elem_position.bdr2 => current_pos = ful3
      case Angle_elem_position.bdr3 => current_pos = ful1
      case Angle_elem_position.fdl1 => current_pos = bur2
      case Angle_elem_position.fdl2 => current_pos = bur3
      case Angle_elem_position.fdl3 => current_pos = bur1
    }
  }
  def L_back_double(): Unit = L_front_double()
  def B_front(): Unit = {
    abstract_pos.B_front(current_pos)
    current_pos match {
      case Angle_elem_position.bul1 => current_pos = bur2
      case Angle_elem_position.bul2 => current_pos = bur1
      case Angle_elem_position.bul3 => current_pos = bur3
      case Angle_elem_position.bur1 => current_pos = bdr1
      case Angle_elem_position.bur2 => current_pos = bdr3
      case Angle_elem_position.bur3 => current_pos = bdr2
      case Angle_elem_position.bdl1 => current_pos = bul1
      case Angle_elem_position.bdl2 => current_pos = bul3
      case Angle_elem_position.bdl3 => current_pos = bul2
      case Angle_elem_position.bdr1 => current_pos = bdl3
      case Angle_elem_position.bdr2 => current_pos = bdl2
      case Angle_elem_position.bdr3 => current_pos = bdl1
    }
  }
  def B_back(): Unit = {
    abstract_pos.B_back(current_pos)
    current_pos match {
      case Angle_elem_position.bul1 => current_pos = bdl1
      case Angle_elem_position.bul2 => current_pos = bdl3
      case Angle_elem_position.bul3 => current_pos = bdl2
      case Angle_elem_position.bur1 => current_pos = bul2
      case Angle_elem_position.bur2 => current_pos = bul1
      case Angle_elem_position.bur3 => current_pos = bul3
      case Angle_elem_position.bdl1 => current_pos = bdr3
      case Angle_elem_position.bdl2 => current_pos = bdr2
      case Angle_elem_position.bdl3 => current_pos = bdr1
      case Angle_elem_position.bdr1 => current_pos = bur1
      case Angle_elem_position.bdr2 => current_pos = bur3
      case Angle_elem_position.bdr3 => current_pos = bur2
    }
  }
  def B_front_double(): Unit = {
    abstract_pos.B_front_double(current_pos)
    current_pos match {
      case Angle_elem_position.bul1 => current_pos = bdr3
      case Angle_elem_position.bul2 => current_pos = bdr1
      case Angle_elem_position.bul3 => current_pos = bdr2
      case Angle_elem_position.bur1 => current_pos = bdl3
      case Angle_elem_position.bur2 => current_pos = bdl1
      case Angle_elem_position.bur3 => current_pos = bdl2
      case Angle_elem_position.bdl1 => current_pos = bur2
      case Angle_elem_position.bdl2 => current_pos = bur3
      case Angle_elem_position.bdl3 => current_pos = bur1
      case Angle_elem_position.bdr1 => current_pos = bul2
      case Angle_elem_position.bdr2 => current_pos = bul3
      case Angle_elem_position.bdr3 => current_pos = bul1
    }
  }
  def B_back_double(): Unit = B_front_double()
}

object Elem_angle extends Angle_value_table
