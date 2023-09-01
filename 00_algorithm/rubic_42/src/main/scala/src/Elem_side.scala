/*
      Elem side

      possible positions with color arrangement:
          | s_0 | s_1 | s_2 | s_3 | s_4 | s_5 | s_6 | s_7 | s_8 | s_9 | s_10| s_11
    fu: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b|w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    fl: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    fr: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    fd: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    lu: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    ld: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    ru: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    rd: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    bu: 1 | W-B | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    bd: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    bl: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
    br: 1 | w|b | w|o | w|r | w|g | o|b | o|g | g|r | r|b | o|y | g|y | r|y | b|y
        2 | b_w | o|w | r|w | g|w | b|o | g|o | r|g | b|r | y|o | y|g | y|r | y|b
 */

package src

import src.Elem_colors.Elem_colors
import src.Elem_side.colors_map_s
import src.Side_elem_position._
import src.Side_position.Side_position

class Elem_side(name: String,
                color_1: Elem_colors,
                val color_2: Elem_colors,
                var current_pos: Side_elem_position,
                var target_pos: Side_elem_position)
  extends Elem(name, color_1) {
  private var colorSequenceFlag: Int = 0 // if 0 -> direct; 1 -> reverse sequense: 0 -> ... color_1, ... color_2, ...; 1 -> reverse
  def get_color(side: Side_position): Char = {
    current_pos match {
        case Side_elem_position.fu1 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.front => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.fu2 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.front => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.fl1 =>
          side match {
            case Side_position.left => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.front => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.fl2 =>
          side match {
            case Side_position.left => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.front => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.fr1 =>
          side match {
            case Side_position.front => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.right => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.fr2 =>
          side match {
            case Side_position.front => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.right => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.fd1 =>
          side match {
            case Side_position.front => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.fd2 =>
          side match {
            case Side_position.front => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.lu1 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.left => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.lu2 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.left => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.ld1 =>
          side match {
            case Side_position.left => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.ld2 =>
          side match {
            case Side_position.left => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.ru1 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.right => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.ru2 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.right => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.rd1 =>
          side match {
            case Side_position.right => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.rd2 =>
          side match {
            case Side_position.right => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.bu1 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.back => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.bu2 =>
          side match {
            case Side_position.up => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.back => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.bd1 =>
          side match {
            case Side_position.back => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.bd2 =>
          side match {
            case Side_position.back => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.down => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.bl1 =>
          side match {
            case Side_position.right => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.back => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.bl2 =>
          side match {
            case Side_position.right => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.back => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
        case Side_elem_position.br1 =>
          side match {
            case Side_position.left => colors_map_s(name)(current_pos.toString)(0) //color_1.toString.head
            case Side_position.back => colors_map_s(name)(current_pos.toString)(1) //color_2.toString.head
          }
        case Side_elem_position.br2 =>
          side match {
            case Side_position.left => colors_map_s(name)(current_pos.toString)(0) //color_2.toString.head
            case Side_position.back => colors_map_s(name)(current_pos.toString)(1) //color_1.toString.head
          }
    }
  }
  def getName: String = name
  def getCurrentPos: Side_elem_position = current_pos
  def getTargetPos: Side_elem_position = target_pos
  def getElemState: Side_elem_position = current_pos
  def checkComplete: Boolean = if (target_pos == current_pos) true else false
  private def updateColorSequenceFlag(colorSequence: Array[Elem_colors]): Unit = {
    colorSequenceFlag match {
      case 0 =>
        if (colorSequence.indexOf(color_1) > colorSequence.indexOf(color_2))
          colorSequenceFlag = 1
      case 1 =>
        if (colorSequence.indexOf(color_1) < colorSequence.indexOf(color_2))
          colorSequenceFlag = 0
    }
  }
  private def checkChangeColorSequence(colorSequence: Array[Elem_colors]): Boolean = {
    colorSequenceFlag match {
      case 0 => if (colorSequence.indexOf(color_1) < colorSequence.indexOf(color_2)) false else true
      case 1 => if (colorSequence.indexOf(color_1) < colorSequence.indexOf(color_2)) true else false
    }
  }
  def x_front(colorSequence: Array[Elem_colors]): Unit = {
    // front -> up
    current_pos match {
      case Side_elem_position.fu1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bu1 else bu2
      case Side_elem_position.fu2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bu2 else bu1
      case Side_elem_position.fd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu1 else fu2
      case Side_elem_position.fd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu2 else fu1
      case Side_elem_position.bu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bd1 else bd2
      case Side_elem_position.bu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bd2 else bd1
      case Side_elem_position.bd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fd1 else fd2
      case Side_elem_position.bd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fd2 else fd1

      case Side_elem_position.fl1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) lu1 else lu2
      case Side_elem_position.fl2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) lu2 else lu1
      case Side_elem_position.fr1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru1 else ru2
      case Side_elem_position.fr2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru2 else ru1

      case Side_elem_position.lu1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br1 else br2
      case Side_elem_position.lu2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br2 else br1
      case Side_elem_position.ld1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fl1 else fl2
      case Side_elem_position.ld2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fl2 else fl1

      case Side_elem_position.bl1 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd1 else rd2
      case Side_elem_position.bl2 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd2 else rd1
      case Side_elem_position.br1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld1 else ld2
      case Side_elem_position.br2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld2 else ld1

      case Side_elem_position.ru1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bl1 else bl2
      case Side_elem_position.ru2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bl2 else bl1
      case Side_elem_position.rd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fr1 else fr2
      case Side_elem_position.rd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fr2 else fr1
    }
    target_pos match {
      case Side_elem_position.fu1 => target_pos = bu1
      case Side_elem_position.fd1 => target_pos = fu1
      case Side_elem_position.fl1 => target_pos = lu1
      case Side_elem_position.fr1 => target_pos = ru1

      case Side_elem_position.lu1 => target_pos = br1
      case Side_elem_position.ld1 => target_pos = fl1
      case Side_elem_position.ru1 => target_pos = bl1
      case Side_elem_position.rd1 => target_pos = fr1

      case Side_elem_position.bu1 => target_pos = bd1
      case Side_elem_position.bl1 => target_pos = rd1
      case Side_elem_position.br1 => target_pos = ld1
      case Side_elem_position.bd1 => target_pos = fd1
    }
    updateColorSequenceFlag(colorSequence)
  }
  def x_back(colorSequence: Array[Elem_colors]): Unit = {
    // front -> down
    current_pos match {
      case Side_elem_position.fu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd1 else fd2
      case Side_elem_position.fu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd2 else fd1
      case Side_elem_position.fd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bd1 else bd2
      case Side_elem_position.fd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bd2 else bd1
      case Side_elem_position.bu1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fu1 else fu2
      case Side_elem_position.bu2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fu2 else fu1
      case Side_elem_position.bd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu1 else bu2
      case Side_elem_position.bd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu2 else bu1

      case Side_elem_position.fl1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld1 else ld2
      case Side_elem_position.fl2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld2 else ld1
      case Side_elem_position.fr1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) rd1 else rd2
      case Side_elem_position.fr2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) rd2 else rd1

      case Side_elem_position.lu1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fl1 else fl2
      case Side_elem_position.lu2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fl2 else fl1
      case Side_elem_position.ld1 => current_pos = if (!checkChangeColorSequence(colorSequence)) br1 else br2
      case Side_elem_position.ld2 => current_pos = if (!checkChangeColorSequence(colorSequence)) br2 else br1

      case Side_elem_position.bl1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) ru1 else ru2
      case Side_elem_position.bl2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) ru2 else ru1
      case Side_elem_position.br1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) lu1 else lu2
      case Side_elem_position.br2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) lu2 else lu1

      case Side_elem_position.ru1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr1 else fr2
      case Side_elem_position.ru2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr2 else fr1
      case Side_elem_position.rd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bl1 else bl2
      case Side_elem_position.rd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bl2 else bl1
    }
    target_pos match {
      case Side_elem_position.fu1 => target_pos = fd1
      case Side_elem_position.fl1 => target_pos = ld1
      case Side_elem_position.fr1 => target_pos = rd1
      case Side_elem_position.fd1 => target_pos = bd1

      case Side_elem_position.lu1 => target_pos = fl1
      case Side_elem_position.ld1 => target_pos = br1
      case Side_elem_position.ru1 => target_pos = fr1
      case Side_elem_position.rd1 => target_pos = bl1

      case Side_elem_position.bu1 => target_pos = fu1
      case Side_elem_position.bl1 => target_pos = ru1
      case Side_elem_position.br1 => target_pos = lu1
      case Side_elem_position.bd1 => target_pos = bu1
    }
    updateColorSequenceFlag(colorSequence)
  }
  def y_front(colorSequence: Array[Elem_colors]): Unit = {
    // front -> left
    current_pos match {
      case Side_elem_position.fl1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br1 else br2
      case Side_elem_position.fl2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br2 else br1
      case Side_elem_position.fr1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fl1 else fl2
      case Side_elem_position.fr2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fl2 else fl1
      case Side_elem_position.bl1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr1 else fr2
      case Side_elem_position.bl2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr2 else fr1
      case Side_elem_position.br1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bl1 else bl2
      case Side_elem_position.br2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bl2 else bl1

      case Side_elem_position.fu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) lu1 else lu2
      case Side_elem_position.fu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) lu2 else lu1
      case Side_elem_position.fd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld1 else ld2
      case Side_elem_position.fd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld2 else ld1

      case Side_elem_position.lu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu1 else bu2
      case Side_elem_position.lu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu2 else bu1
      case Side_elem_position.ld1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bd1 else bd2
      case Side_elem_position.ld2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bd2 else bd1

      case Side_elem_position.bu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru1 else ru2
      case Side_elem_position.bu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru2 else ru1
      case Side_elem_position.bd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd1 else ru2
      case Side_elem_position.bd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd2 else rd1

      case Side_elem_position.ru1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu1 else fu2
      case Side_elem_position.ru2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu2 else fu1
      case Side_elem_position.rd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd1 else fd2
      case Side_elem_position.rd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd2 else fd1
    }
    target_pos match {
      case Side_elem_position.fu1 => target_pos = lu1
      case Side_elem_position.fl1 => target_pos = br1
      case Side_elem_position.fr1 => target_pos = fl1
      case Side_elem_position.fd1 => target_pos = ld1

      case Side_elem_position.lu1 => target_pos = bu1
      case Side_elem_position.ld1 => target_pos = bd1
      case Side_elem_position.ru1 => target_pos = fu1
      case Side_elem_position.rd1 => target_pos = fd1

      case Side_elem_position.bu1 => target_pos = ru1
      case Side_elem_position.bl1 => target_pos = fr1
      case Side_elem_position.br1 => target_pos = bl1
      case Side_elem_position.bd1 => target_pos = rd1
    }
    updateColorSequenceFlag(colorSequence)
  }
  def y_back(colorSequence: Array[Elem_colors]): Unit = {
    // front -> right
    current_pos match {
      case Side_elem_position.fl1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr1 else fr2
      case Side_elem_position.fl2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr2 else fr1
      case Side_elem_position.fr1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bl1 else bl2
      case Side_elem_position.fr2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bl2 else bl1
      case Side_elem_position.bl1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br1 else br2
      case Side_elem_position.bl2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br2 else br1
      case Side_elem_position.br1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fl1 else fl2
      case Side_elem_position.br2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fl2 else fl1

      case Side_elem_position.fu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru1 else ru2
      case Side_elem_position.fu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru2 else ru1
      case Side_elem_position.fd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd1 else rd2
      case Side_elem_position.fd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd2 else rd1

      case Side_elem_position.lu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu1 else fu2
      case Side_elem_position.lu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu2 else fu1
      case Side_elem_position.ld1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd1 else fd2
      case Side_elem_position.ld2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd2 else fd1

      case Side_elem_position.bu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) lu1 else lu2
      case Side_elem_position.bu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) lu2 else lu1
      case Side_elem_position.bd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld1 else ld2
      case Side_elem_position.bd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld2 else ld1

      case Side_elem_position.ru1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu1 else bu2
      case Side_elem_position.ru2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu2 else bu1
      case Side_elem_position.rd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bd1 else bd2
      case Side_elem_position.rd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bd2 else bd1
    }
    target_pos match {
      case Side_elem_position.fu1 => target_pos = ru1
      case Side_elem_position.fl1 => target_pos = fr1
      case Side_elem_position.fr1 => target_pos = bl1
      case Side_elem_position.fd1 => target_pos = rd1

      case Side_elem_position.lu1 => target_pos = fu1
      case Side_elem_position.ld1 => target_pos = fd1
      case Side_elem_position.ru1 => target_pos = bu1
      case Side_elem_position.rd1 => target_pos = bd1

      case Side_elem_position.bu1 => target_pos = lu1
      case Side_elem_position.bl1 => target_pos = br1
      case Side_elem_position.br1 => target_pos = fl1
      case Side_elem_position.bd1 => target_pos = ld1
    }
    updateColorSequenceFlag(colorSequence)
  }
  def z_front(colorSequence: Array[Elem_colors]): Unit = {
    // up -> right
//    if (current_pos == Side_elem_position.ru2) println(s"zzzzzzzzzzzzzz ${colorSequence.mkString(", ")}, ${checkChangeColorSequence(colorSequence)}")
    current_pos match {
      case Side_elem_position.ru1 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd1 else rd2
      case Side_elem_position.ru2 => current_pos = if (!checkChangeColorSequence(colorSequence)) rd2 else rd1
      case Side_elem_position.rd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) ld1 else ld2
      case Side_elem_position.rd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) ld2 else ld1
      case Side_elem_position.lu1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) ru1 else ru2
      case Side_elem_position.lu2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) ru2 else ru1
      case Side_elem_position.ld1 => current_pos = if (!checkChangeColorSequence(colorSequence)) lu1 else lu2
      case Side_elem_position.ld2 => current_pos = if (!checkChangeColorSequence(colorSequence)) lu2 else lu1

      case Side_elem_position.fu1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fr1 else fr2
      case Side_elem_position.fu2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fr2 else fr1
      case Side_elem_position.fl1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu1 else fu2
      case Side_elem_position.fl2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fu2 else fu1
      case Side_elem_position.fr1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd1 else fd2
      case Side_elem_position.fr2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fd2 else fd1
      case Side_elem_position.fd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fl1 else fl2
      case Side_elem_position.fd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fl2 else fl1

      case Side_elem_position.bu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bl1 else bl2
      case Side_elem_position.bu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bl2 else bl1
      case Side_elem_position.bl1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bd1 else bd2
      case Side_elem_position.bl2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bd2 else bd1
      case Side_elem_position.br1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu1 else bu2
      case Side_elem_position.br2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu2 else bu1
      case Side_elem_position.bd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br1 else br2
      case Side_elem_position.bd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) br2 else br1
    }
    target_pos match {
      case Side_elem_position.fu1 => target_pos = fr1
      case Side_elem_position.fl1 => target_pos = fu1
      case Side_elem_position.fr1 => target_pos = fd1
      case Side_elem_position.fd1 => target_pos = fl1

      case Side_elem_position.lu1 => target_pos = ru1
      case Side_elem_position.ld1 => target_pos = lu1
      case Side_elem_position.ru1 => target_pos = rd1
      case Side_elem_position.rd1 => target_pos = ld1

      case Side_elem_position.bu1 => target_pos = bl1
      case Side_elem_position.bl1 => target_pos = bd1
      case Side_elem_position.br1 => target_pos = bu1
      case Side_elem_position.bd1 => target_pos = br1
    }
    updateColorSequenceFlag(colorSequence)
  }
  def z_back(colorSequence: Array[Elem_colors]): Unit = {
    // up -> left
    current_pos match {
      case Side_elem_position.ru1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) lu1 else lu2
      case Side_elem_position.ru2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) lu2 else lu1
      case Side_elem_position.rd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru1 else ru2//+
      case Side_elem_position.rd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ru2 else ru1//+
      case Side_elem_position.lu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld1 else ld2//+
      case Side_elem_position.lu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) ld2 else ld1//+
      case Side_elem_position.ld1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) rd1 else rd2
      case Side_elem_position.ld2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) rd2 else rd1

      case Side_elem_position.fu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fl1 else fl2//+
      case Side_elem_position.fu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fl2 else fl1//+
      case Side_elem_position.fl1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fd1 else fd2
      case Side_elem_position.fl2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fd2 else fd1
      case Side_elem_position.fr1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fu1 else fu2
      case Side_elem_position.fr2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) fu2 else fu1
      case Side_elem_position.fd1 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr1 else fr2//+
      case Side_elem_position.fd2 => current_pos = if (!checkChangeColorSequence(colorSequence)) fr2 else fr1//+

      case Side_elem_position.bu1 => current_pos = if (!checkChangeColorSequence(colorSequence)) br1 else br2//+
      case Side_elem_position.bu2 => current_pos = if (!checkChangeColorSequence(colorSequence)) br2 else br1//+
      case Side_elem_position.bl1 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu1 else bu2//+
      case Side_elem_position.bl2 => current_pos = if (!checkChangeColorSequence(colorSequence)) bu2 else bu1//+
      case Side_elem_position.br1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bd1 else bd2
      case Side_elem_position.br2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bd2 else bd1
      case Side_elem_position.bd1 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bl1 else bl2
      case Side_elem_position.bd2 => current_pos = if (checkChangeColorSequence(colorSequence) || checkComplete) bl2 else bl1
    }
    target_pos match {
      case Side_elem_position.fu1 => target_pos = fl1
      case Side_elem_position.fl1 => target_pos = fd1
      case Side_elem_position.fr1 => target_pos = fu1
      case Side_elem_position.fd1 => target_pos = fr1

      case Side_elem_position.lu1 => target_pos = ld1
      case Side_elem_position.ld1 => target_pos = rd1
      case Side_elem_position.ru1 => target_pos = lu1
      case Side_elem_position.rd1 => target_pos = ru1

      case Side_elem_position.bu1 => target_pos = br1
      case Side_elem_position.bl1 => target_pos = bu1
      case Side_elem_position.br1 => target_pos = bd1
      case Side_elem_position.bd1 => target_pos = bl1
    }
    updateColorSequenceFlag(colorSequence)
  }
  def F_front(): Unit = {
    current_pos match {
      case Side_elem_position.fu1 => current_pos = fr2
      case Side_elem_position.fu2 => current_pos = fr1
      case Side_elem_position.fl1 => current_pos = fu1
      case Side_elem_position.fl2 => current_pos = fu2
      case Side_elem_position.fr1 => current_pos = fd1
      case Side_elem_position.fr2 => current_pos = fd2
      case Side_elem_position.fd1 => current_pos = fl2
      case Side_elem_position.fd2 => current_pos = fl1
    }
  }
  def F_back() = {
    current_pos match {
      case Side_elem_position.fu1 => current_pos = fl1
      case Side_elem_position.fu2 => current_pos = fl2
      case Side_elem_position.fl1 => current_pos = fd2
      case Side_elem_position.fl2 => current_pos = fd1
      case Side_elem_position.fr1 => current_pos = fu2
      case Side_elem_position.fr2 => current_pos = fu1
      case Side_elem_position.fd1 => current_pos = fr1
      case Side_elem_position.fd2 => current_pos = fr2
    }
  }
  def F_front_double() = {
    current_pos match {
      case Side_elem_position.fu1 => current_pos = fd2
      case Side_elem_position.fu2 => current_pos = fd1
      case Side_elem_position.fl1 => current_pos = fr2
      case Side_elem_position.fl2 => current_pos = fr1
      case Side_elem_position.fr1 => current_pos = fl2
      case Side_elem_position.fr2 => current_pos = fl1
      case Side_elem_position.fd1 => current_pos = fu2
      case Side_elem_position.fd2 => current_pos = fu1
    }
  }
  def F_back_double() = F_front_double()
  def U_front() = {
    current_pos match {
      case Side_elem_position.fu1 => current_pos = lu1
      case Side_elem_position.fu2 => current_pos = lu2
      case Side_elem_position.lu1 => current_pos = bu1
      case Side_elem_position.lu2 => current_pos = bu2
      case Side_elem_position.ru1 => current_pos = fu1
      case Side_elem_position.ru2 => current_pos = fu2
      case Side_elem_position.bu1 => current_pos = ru1
      case Side_elem_position.bu2 => current_pos = ru2
    }
  }
  def U_back() = {
    current_pos match {
      case Side_elem_position.fu1 => current_pos = ru1
      case Side_elem_position.fu2 => current_pos = ru2
      case Side_elem_position.lu1 => current_pos = fu1
      case Side_elem_position.lu2 => current_pos = fu2
      case Side_elem_position.ru1 => current_pos = bu1
      case Side_elem_position.ru2 => current_pos = bu2
      case Side_elem_position.bu1 => current_pos = lu1
      case Side_elem_position.bu2 => current_pos = lu2
    }
  }
  def U_front_double() = {
    current_pos match {
      case Side_elem_position.fu1 => current_pos = bu1
      case Side_elem_position.fu2 => current_pos = bu2
      case Side_elem_position.lu1 => current_pos = ru1
      case Side_elem_position.lu2 => current_pos = ru2
      case Side_elem_position.ru1 => current_pos = lu1
      case Side_elem_position.ru2 => current_pos = lu2
      case Side_elem_position.bu1 => current_pos = fu1
      case Side_elem_position.bu2 => current_pos = fu2
    }
  }
  def U_back_double() = U_front_double()
  def D_front() = {
    current_pos match {
      case Side_elem_position.fd1 => current_pos = rd1
      case Side_elem_position.fd2 => current_pos = rd2
      case Side_elem_position.ld1 => current_pos = fd1
      case Side_elem_position.ld2 => current_pos = fd2
      case Side_elem_position.rd1 => current_pos = bd1
      case Side_elem_position.rd2 => current_pos = bd2
      case Side_elem_position.bd1 => current_pos = ld1
      case Side_elem_position.bd2 => current_pos = ld2
    }
  }
  def D_back() = {
    current_pos match {
      case Side_elem_position.fd1 => current_pos = ld1
      case Side_elem_position.fd2 => current_pos = ld2
      case Side_elem_position.ld1 => current_pos = bd1
      case Side_elem_position.ld2 => current_pos = bd2
      case Side_elem_position.rd1 => current_pos = fd1
      case Side_elem_position.rd2 => current_pos = fd2
      case Side_elem_position.bd1 => current_pos = rd1
      case Side_elem_position.bd2 => current_pos = rd2
    }
  }
  def D_front_double() = {
    current_pos match {
      case Side_elem_position.fd1 => current_pos = bd1
      case Side_elem_position.fd2 => current_pos = bd2
      case Side_elem_position.ld1 => current_pos = rd1
      case Side_elem_position.ld2 => current_pos = rd2
      case Side_elem_position.rd1 => current_pos = ld1
      case Side_elem_position.rd2 => current_pos = ld2
      case Side_elem_position.bd1 => current_pos = fd1
      case Side_elem_position.bd2 => current_pos = fd2
    }
  }
  def D_back_double() = D_front_double()
  def R_front() = {
    current_pos match {
      case Side_elem_position.ru1 => current_pos = bl2
      case Side_elem_position.ru2 => current_pos = bl1
      case Side_elem_position.fr1 => current_pos = ru1
      case Side_elem_position.fr2 => current_pos = ru2
      case Side_elem_position.bl1 => current_pos = rd1
      case Side_elem_position.bl2 => current_pos = rd2
      case Side_elem_position.rd1 => current_pos = fr2
      case Side_elem_position.rd2 => current_pos = fr1
    }
  }
  def R_back() = {
    current_pos match {
      case Side_elem_position.ru1 => current_pos = fr1
      case Side_elem_position.ru2 => current_pos = fr2
      case Side_elem_position.fr1 => current_pos = rd2
      case Side_elem_position.fr2 => current_pos = rd1
      case Side_elem_position.bl1 => current_pos = ru2
      case Side_elem_position.bl2 => current_pos = ru1
      case Side_elem_position.rd1 => current_pos = bl1
      case Side_elem_position.rd2 => current_pos = bl2
    }
  }
  def R_front_double() = {
    current_pos match {
      case Side_elem_position.ru1 => current_pos = rd2
      case Side_elem_position.ru2 => current_pos = rd1
      case Side_elem_position.fr1 => current_pos = bl2
      case Side_elem_position.fr2 => current_pos = bl1
      case Side_elem_position.bl1 => current_pos = fr2
      case Side_elem_position.bl2 => current_pos = fr1
      case Side_elem_position.rd1 => current_pos = ru2
      case Side_elem_position.rd2 => current_pos = ru1
    }
  }
  def R_back_double() = R_front_double()
  def L_front() = {
    current_pos match {
      case Side_elem_position.lu1 => current_pos = fl2
      case Side_elem_position.lu2 => current_pos = fl1
      case Side_elem_position.fl1 => current_pos = ld1
      case Side_elem_position.fl2 => current_pos = ld2
      case Side_elem_position.br1 => current_pos = lu2
      case Side_elem_position.br2 => current_pos = lu1
      case Side_elem_position.ld1 => current_pos = br1
      case Side_elem_position.ld2 => current_pos = br2
    }
  }
  def L_back() = {
    current_pos match {
      case Side_elem_position.lu1 => current_pos = br2
      case Side_elem_position.lu2 => current_pos = br1
      case Side_elem_position.fl1 => current_pos = lu2
      case Side_elem_position.fl2 => current_pos = lu1
      case Side_elem_position.br1 => current_pos = ld1
      case Side_elem_position.br2 => current_pos = ld2
      case Side_elem_position.ld1 => current_pos = fl1
      case Side_elem_position.ld2 => current_pos = fl2
    }
  }
  def L_front_double() = {
    current_pos match {
      case Side_elem_position.lu1 => current_pos = ld2
      case Side_elem_position.lu2 => current_pos = ld1
      case Side_elem_position.fl1 => current_pos = br1
      case Side_elem_position.fl2 => current_pos = br2
      case Side_elem_position.br1 => current_pos = fl1
      case Side_elem_position.br2 => current_pos = fl2
      case Side_elem_position.ld1 => current_pos = lu2
      case Side_elem_position.ld2 => current_pos = lu1
    }
  }
  def L_back_double() = L_front_double()
  def B_front() = {
    current_pos match {
      case Side_elem_position.bu1 => current_pos = br1
      case Side_elem_position.bu2 => current_pos = br2
      case Side_elem_position.bl1 => current_pos = bu1
      case Side_elem_position.bl2 => current_pos = bu2
      case Side_elem_position.br1 => current_pos = bd2
      case Side_elem_position.br2 => current_pos = bd1
      case Side_elem_position.bd1 => current_pos = bl2
      case Side_elem_position.bd2 => current_pos = bl1
    }
  }
  def B_back() = {
    current_pos match {
      case Side_elem_position.bu1 => current_pos = bl1
      case Side_elem_position.bu2 => current_pos = bl2
      case Side_elem_position.bl1 => current_pos = bd2
      case Side_elem_position.bl2 => current_pos = bd1
      case Side_elem_position.br1 => current_pos = bu1
      case Side_elem_position.br2 => current_pos = bu2
      case Side_elem_position.bd1 => current_pos = br2
      case Side_elem_position.bd2 => current_pos = br1
    }
  }
  def B_front_double() = {
    current_pos match {
      case Side_elem_position.bu1 => current_pos = bd2
      case Side_elem_position.bu2 => current_pos = bd1
      case Side_elem_position.bl1 => current_pos = br1
      case Side_elem_position.bl2 => current_pos = br2
      case Side_elem_position.br1 => current_pos = bl1
      case Side_elem_position.br2 => current_pos = bl2
      case Side_elem_position.bd1 => current_pos = bu2
      case Side_elem_position.bd2 => current_pos = bu1
    }
  }
  def B_back_double() = B_front_double()
}

object Elem_side extends Side_value_table {}
