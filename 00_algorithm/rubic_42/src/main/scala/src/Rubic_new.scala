/*
      rubic map:
    ---|---|---|U1W|U2W|U3W|---|---|---|---|---|---|
    ---|---|---|U4W|U5W|U6W|---|---|---|---|---|---|
    ---|---|---|U7W|U8W|U9W|---|---|---|---|---|---|
    L1O|L2O|L3O|F1G|F2G|F3G|R1R|R2R|R3R|B1B|B2B|B3B|
    L4O|L5O|L6O|F4G|F5G|F6G|R4R|R5R|R6R|B4B|B5B|B6B|
    L7O|L8O|L9O|F7G|F8G|F9G|R7R|R8R|R9R|B7B|B8B|B9B|
    ---|---|---|D1Y|D2Y|D3Y|---|---|---|---|---|---|
    ---|---|---|D4Y|D5Y|D6Y|---|---|---|---|---|---|
    ---|---|---|D7Y|D8Y|D9Y|---|---|---|---|---|---|

      rubic map with name elements:
    ----|----|----|a_0 |s_0 |a_1 |----|----|----|----|----|----|
    ----|----|----|s_1 |c_0 |s_2 |----|----|----|----|----|----|
    ----|----|----|a_2 |s_3 |a_3 |----|----|----|----|----|----|
    a_0 |s_1 |a_2 |a_2 |s_3 |a_3 |a_3 |s_2 |a_1 |a_1 |s_0 |a_0 |
    s_4 |c_1 |s_5 |s_5 |c_2 |s_6 |s_6 |c_3 |s_7 |s_7 |c_4 |s_4 |
    a_6 |s_8 |a_4 |a_4 |s_9 |a_5 |a_5 |s_10|a_7 |a_7 |s_11|a_6 |
    ----|----|----|a_4 |s_9 |a_5 |----|----|----|----|----|----|
    ----|----|----|s_8 |c_5 |s_10|----|----|----|----|----|----|
    ----|----|----|a_6 |s_11|a_7 |----|----|----|----|----|----|

      rubic elements with position name:
    ----|----|----|bur_|bu_ |bul_|----|----|----|----|----|----|
    ----|----|----|lu_ |uu  |ru_ |----|----|----|----|----|----|
    ----|----|----|ful_|fu_ |fur_|----|----|----|----|----|----|
    bur_|lu_ |ful_|ful_|fu_ |fur_|fur_|ru_ |bul_|bul_|bu_ |bur_|
    br_ |ll  |fl_ |fl_ |ff  |fr_ |fr_ |rr  |bl_ |bl_ |bb  |br_ |
    bdr_|ld_ |fdl_|fdl_|fd_ |fdr_|fdr_|rd_ |bdl_|bdl_|bd_ |bdr_|
    ----|----|----|fdl_|fd_ |fdr_|----|----|----|----|----|----|
    ----|----|----|ld_ |dd  |rd_ |----|----|----|----|----|----|
    ----|----|----|bdr_|bd_ |bdl_|----|----|----|----|----|----|

      side rubic : color:
    front:G   green
    up:W      white
    down:Y    yellow
    right:R   red
    left:O    orange
    back:B    blue

      General side sequence:
    U L F R B D

      General color sequence:
    W O G R B Y
 */

package src

import src.Angle_elem_position._
import src.Center_elem_position._
import src.Elem_colors._
import src.OppositeState.OppositeState
import src.Rubic_new.{collectionAngleMoviesForPrepareF2L, collectionAngleMoviesFullSideFirst, collectionCOLL, collectionMoviesForF2L, collectionOppositeCrossAfterF2L, collectionPLL, collectionSideMoviesCrestFirst, collectionSideMoviesForPrapareF2L, collectionSideMoviesSecondLayer}
import src.Side_composition.Side_composition
import src.Side_elem_position._
import src.Side_position._
import src.Side_position_with_rubic.Side_position_with_rubic
import src.State_for_Fridrih_F2L.State_for_Fridrih_F2L
import src.State_for_Fridrih_OLL.State_for_Fridrih_OLL
import src.State_for_Fridrih_PLL.State_for_Fridrih_PLL

import scala.collection.mutable.ArrayBuffer
import scala.math.Ordering.Implicits.infixOrderingOps

class Rubic_new {
  private val colorSequence = Array[Elem_colors](white, orange, green, red, blue, yellow)

  // Angle elems:
  private val angle_0 = new Elem_angle("a__0", white, orange, blue, bur1, bur1,
    new AbstractPositionForAngleElem(white, orange, no_color, no_color, blue, no_color))
  private val angle_1 = new Elem_angle("a__1", white, red, blue, bul1, bul1,
    new AbstractPositionForAngleElem(white, no_color, no_color, red, blue, no_color))
  private val angle_2 = new Elem_angle("a__2", white, orange, green, ful1, ful1,
    new AbstractPositionForAngleElem(white, orange, green, no_color, no_color, no_color))
  private val angle_3 = new Elem_angle("a__3", white, green, red, fur1, fur1,
    new AbstractPositionForAngleElem(white, no_color, green, red, no_color, no_color))
  private val angle_4 = new Elem_angle("a__4", orange, green, yellow, fdl1, fdl1,
    new AbstractPositionForAngleElem(no_color, orange, green, no_color, no_color, yellow))
  private val angle_5 = new Elem_angle("a__5", green, red, yellow, fdr1, fdr1,
    new AbstractPositionForAngleElem(no_color, no_color, green, red, no_color, yellow))
  private val angle_6 = new Elem_angle("a__6", orange, blue, yellow, bdr1, bdr1,
    new AbstractPositionForAngleElem(no_color, orange, no_color, no_color, blue, yellow))
  private val angle_7 = new Elem_angle("a__7", red, blue, yellow, bdl1, bdl1,
    new AbstractPositionForAngleElem(no_color, no_color, no_color, red, blue, yellow))
  private def allAngleElems = Array(angle_0, angle_1, angle_2, angle_3, angle_4, angle_5,
                                angle_6, angle_7)

  // Side elems:
  private val side_0 = new Elem_side("s__0", white, blue, bu1, bu1)
  private val side_1 = new Elem_side("s__1", white, orange, lu1, lu1)
  private val side_2 = new Elem_side("s__2", white, red, ru1, ru1)
  private val side_3 = new Elem_side("s__3", white, green, fu1, fu1)
  private val side_4 = new Elem_side("s__4", orange, blue, br1, br1)
  private val side_5 = new Elem_side("s__5", orange, green, fl1, fl1)
  private val side_6 = new Elem_side("s__6", green, red, fr1, fr1)
  private val side_7 = new Elem_side("s__7", red, blue, bl1, bl1)
  private val side_8 = new Elem_side("s__8", orange, yellow, ld1, ld1)
  private val side_9 = new Elem_side("s__9", green, yellow, fd1, fd1)
  private val side_10 = new Elem_side("s_10", red, yellow, rd1, rd1)
  private val side_11 = new Elem_side("s_11", blue, yellow, bd1, bd1)
  private def allSideElems = Array(side_0, side_1, side_2, side_3, side_4, side_5, side_6, side_7, side_8, side_9, side_10, side_11)

  // Center elems:
  private val center_0 = new Elem_center("c__0", white, uu, uu)
  private val center_1 = new Elem_center("c__1", orange, ll, ll)
  private val center_2 = new Elem_center("c__2", green, ff, ff)
  private val center_3 = new Elem_center("c__3", red, rr, rr)
  private val center_4 = new Elem_center("c__4", blue, bb, bb)
  private val center_5 = new Elem_center("c__5", yellow, dd, dd)
  private def allCenterElems = Array(center_0, center_1, center_2, center_3,
                                     center_4, center_5)

  // Sides elements:
  private val side_up =
    new Side(up,
      angle_0, side_0, angle_1,
      side_1, center_0, side_2,
      angle_2, side_3, angle_3)
  private val side_left =
    new Side(left,
      angle_0, side_1, angle_2,
      side_4, center_1, side_5,
      angle_6, side_8, angle_4)
  private val side_front =
    new Side(front,
      angle_2, side_3, angle_3,
      side_5, center_2, side_6,
      angle_4, side_9, angle_5)
  private val side_right =
    new Side(right,
      angle_3, side_2, angle_1,
      side_6, center_3, side_7,
      angle_5, side_10, angle_7)
  private val side_back =
    new Side(back,
      angle_1, side_0, angle_0,
      side_7, center_4, side_4,
      angle_7, side_11, angle_6)
  private val side_down =
    new Side(down,
      angle_4, side_9, angle_5,
      side_8, center_5, side_10,
      angle_6, side_11, angle_7)
  private def all_sides = Array(side_up, side_left, side_front, side_right, side_back, side_down)
  private val allSteps: ArrayBuffer[String] = ArrayBuffer[String]().empty
  private def cNS(str: String): String = str + (" " * (4 - str.length))

  private def reversePositionForFinalStateSideElem(side_elem_position: Side_elem_position): Side_elem_position = {
    side_elem_position match {
      case Side_elem_position.fl1 => fl1
      case Side_elem_position.fl2 => fl1
      case Side_elem_position.fu1 => fu1
      case Side_elem_position.fu2 => fu1
      case Side_elem_position.ld1 => ld1
      case Side_elem_position.ld2 => ld1
      case Side_elem_position.lu1 => lu1
      case Side_elem_position.lu2 => lu1
      case Side_elem_position.fd1 => fd1
      case Side_elem_position.fd2 => fd1
      case Side_elem_position.fr1 => fr1
      case Side_elem_position.fr2 => fr1
      case Side_elem_position.ru1 => ru1
      case Side_elem_position.ru2 => ru1
      case Side_elem_position.rd1 => rd1
      case Side_elem_position.rd2 => rd1
      case Side_elem_position.bu1 => bu1
      case Side_elem_position.bu2 => bu1
      case Side_elem_position.bl1 => bl1
      case Side_elem_position.bl2 => bl1
      case Side_elem_position.br1 => br1
      case Side_elem_position.br2 => br1
      case Side_elem_position.bd1 => bd1
      case Side_elem_position.bd2 => bd1
    }
  }
  private def reversePositionForFinalStateAngleElem(angleElemPosition: Angle_elem_position): Angle_elem_position = {
    angleElemPosition match {
      case Angle_elem_position.ful1 => ful1
      case Angle_elem_position.ful2 => ful1
      case Angle_elem_position.ful3 => ful1
      case Angle_elem_position.fur1 => fur1
      case Angle_elem_position.fur2 => fur1
      case Angle_elem_position.fur3 => fur1
      case Angle_elem_position.fdl1 => fdl1
      case Angle_elem_position.fdl2 => fdl1
      case Angle_elem_position.fdl3 => fdl1
      case Angle_elem_position.fdr1 => fdr1
      case Angle_elem_position.fdr2 => fdr1
      case Angle_elem_position.fdr3 => fdr1
      case Angle_elem_position.bul1 => bul1
      case Angle_elem_position.bul2 => bul1
      case Angle_elem_position.bul3 => bul1
      case Angle_elem_position.bur1 => bur1
      case Angle_elem_position.bur2 => bur1
      case Angle_elem_position.bur3 => bur1
      case Angle_elem_position.bdl1 => bdl1
      case Angle_elem_position.bdl2 => bdl1
      case Angle_elem_position.bdl3 => bdl1
      case Angle_elem_position.bdr1 => bdr1
      case Angle_elem_position.bdr2 => bdr1
      case Angle_elem_position.bdr3 => bdr1
    }
  }
  private def getNextRequiredSideElemForFirstLayer(side: Side): Elem_side = side.getNextReqSideElem
  private def getNextRequiredAngleElemForFirstLayer(side: Side): Elem_angle = side.getNextReqAngleElem
  private def getNextRequiredSideElemForSecondLayer(startSide: Side): Elem_side = {
    startSide.getPosition match {
      case Side_position.up =>
        if (!side_left.checkSecondLayerComplete(startSide.getPosition))
          side_left.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
        else
          side_right.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
      case Side_position.left =>
        if (!side_front.checkSecondLayerComplete(startSide.getPosition))
          side_front.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
        else
          side_back.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
      case Side_position.front =>
        if (!side_left.checkSecondLayerComplete(startSide.getPosition))
          side_left.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
        else
          side_right.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
      case Side_position.right =>
        if (!side_front.checkSecondLayerComplete(startSide.getPosition))
          side_front.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
        else
          side_back.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
      case Side_position.back =>
        if (!side_left.checkSecondLayerComplete(startSide.getPosition))
          side_left.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
        else
          side_right.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
      case Side_position.down =>
        if (!side_front.checkSecondLayerComplete(startSide.getPosition))
          side_front.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
        else
          side_back.getNextRequiredSideElemForSecondLayer(startSide.getPosition)
    }
  }
  private def searchSideElemInRubic(targetPos: Side_elem_position): Elem_side = {
    val res = new ArrayBuffer[Elem_side]().empty
//    println(s"searchSideElemInRubic start: $targetPos")
    (for (arr <- all_sides) yield arr.allSideElems).foreach{ arr =>
      arr.foreach{ elem =>
//        println(s"search: ${elem.getTargetPos}")
        if (elem.target_pos == targetPos)
          res += elem
      }
    }
//    println(s"searchSideElemInRubic size = ${res.length}")
//    res.foreach(elem => println(elem.getName))
//    println(s"side_1 ${side_1.getTargetPos}")
    res(0)
  }
  private def searchAngleElemInRubic(targetPos: Angle_elem_position): Elem_angle = {
    val res = new ArrayBuffer[Elem_angle]().empty
    (for (arr <- all_sides) yield arr.allAngleElems).foreach { arr =>
      arr.foreach { elem =>
        if (elem.target_pos == targetPos)
          res += elem
      }
    }
    res(0)
  }
  private def getNeededMoviesForSideFirstLayer(currentPos: Side_elem_position,
                                               targetPos: Side_elem_position,
                                               side: Side_position): Array[String] = {
//    println(s"step: curPos: ${currentPos.toString}; targetPos: ${targetPos.toString}; side: ${side.toString}")
    collectionSideMoviesCrestFirst(currentPos, targetPos, side)
  }
  private def getNeededMoviesForAngleFirstLayer(currentPos: Angle_elem_position,
                                                targetPos: Angle_elem_position,
                                                side: Side_position): Array[String] = {
//    println(s"step: curPos: ${currentPos.toString}; targetPos: ${targetPos.toString}; side: ${side.toString}")
    collectionAngleMoviesFullSideFirst(currentPos, targetPos, side)
  }
  private def getNeededMoviesForSideSecondLayer(currentPos: Side_elem_position,
                                                targetPos: Side_elem_position,
                                                side: Side_position): Array[String] = {
    //    println(s"step: curPos: ${currentPos.toString}; targetPos: ${targetPos.toString}; side: ${side.toString}")
    collectionSideMoviesSecondLayer(currentPos, targetPos, side)
  }
  private def getNeededMoviesForOppositeSideCrestFirst(oppositeSide: Side_position): Array[String] = {
    // May check complete angle side elems or line elems for save several steps
    oppositeSide match {
      case Side_position.up => Array("F", "R", "U", "R'", "U'", "F'")
      case Side_position.left => Array("F", "U", "L", "U'", "L'", "F'")
      case Side_position.front => Array("D", "R", "F", "R'", "F'", "D'")
      case Side_position.right => Array("F", "D", "R", "D'", "R'", "F'")
      case Side_position.back => Array("U", "R", "B", "R'", "B'", "U'")
      case Side_position.down => Array("B", "R", "D", "R'", "D'", "B")
    }
  }
//  private def getNeededMoviesForOppositeSideCrestFinal(currentPos: Side_elem_position, // Not work
//                                                       targetPos: Side_elem_position,
//                                                       side: Side_position): Array[String] = {
//    // Change front_top_side elem and left_top_side elem in crest
//    side match {
//      case Side_position.up => Array("R", "U", "R'", "U", "R", "U2", "R'", "U")
//      case Side_position.left => Array("U", "L", "U'", "L", "U", "L2", "U'", "L")
//      case Side_position.front => Array("R", "F", "R'", "F", "R", "F2", "R'", "F")
//      case Side_position.right => Array("D", "R", "D'", "R", "D", "R2", "D'", "R")
//      case Side_position.back => Array("R", "B", "R'", "B", "R", "B2", "R'", "B")
//      case Side_position.down => Array("R", "D", "R'", "D", "R", "D2", "R'", "D")
//    }
//  }

  def prepareShows(): Unit = {
    val aFewMoreSteps = ArrayBuffer[String]()
    for (step <- allSteps) {
      step match {
        case "x" => aFewMoreSteps += "x'"
        case "x'" => aFewMoreSteps += "x"
        case "y" => aFewMoreSteps += "y'"
        case "y'" => aFewMoreSteps += "y"
        case "z" => aFewMoreSteps += "z'"
        case "z'" => aFewMoreSteps += "z"
        case _ =>
      }
    }
    execSteps(aFewMoreSteps.toArray.reverse)
  }
  def show_rubic_color(normalise: Boolean = false): Unit = {
    if (normalise) prepareShows()
    val up = side_up.mkString()
    val left = side_left.mkString()
    val front = side_front.mkString()
    val right = side_right.mkString()
    val back = side_back.mkString()
    val down = side_down.mkString()
    val str = "|-|-|-|" + up.substring(0, 3).toArray.mkString("|") + "|-|-|-|-|-|-|" + '\n' +
      "|-|-|-|" + up.substring(3, 6).toArray.mkString("|") + "|-|-|-|-|-|-|" + '\n' +
      "|-|-|-|" + up.substring(6, 9).toArray.mkString("|") + "|-|-|-|-|-|-|" + '\n' +
      '|' + left.substring(0, 3).toArray.mkString("|") + '|' + front.substring(0, 3).toArray.mkString("|") +
      '|' + right.substring(0, 3).toArray.mkString("|") + '|' + back.substring(0, 3).toArray.mkString("|") + "|\n" +
      '|' + left.substring(3, 6).toArray.mkString("|") + '|' + front.substring(3, 6).toArray.mkString("|") +
      '|' + right.substring(3, 6).toArray.mkString("|") + '|' + back.substring(3, 6).toArray.mkString("|") + "|\n" +
      '|' + left.substring(6, 9).toArray.mkString("|") + '|' + front.substring(6, 9).toArray.mkString("|") +
      '|' + right.substring(6, 9).toArray.mkString("|") + '|' + back.substring(6, 9).toArray.mkString("|") + "|\n" +
      "|-|-|-|" + down.substring(0, 3).toArray.mkString("|") + "|-|-|-|-|-|-|" + '\n' +
      "|-|-|-|" + down.substring(3, 6).toArray.mkString("|") + "|-|-|-|-|-|-|" + '\n' +
      "|-|-|-|" + down.substring(6, 9).toArray.mkString("|") + "|-|-|-|-|-|-|"
    println(str)
  }
  def show_rubic_elements(): Unit = {
    val up = side_up.getNameElems
    val left = side_left.getNameElems
    val front = side_front.getNameElems
    val right = side_right.getNameElems
    val back = side_back.getNameElems
    val down = side_down.getNameElems
    val str = "|----|----|----|" + up(0) + '|' + up(1) + '|' + up(2) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + up(3) + '|' + up(4) + '|' + up(5) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + up(6) + '|' + up(7) + '|' + up(8) + "|----|----|----|----|----|----|" + '\n' +
      '|' + left(0) + '|' + left(1) + '|' + left(2) + '|' + front(0) + '|' + front(1) + '|' + front(2) +
      '|' + right(0) + '|' + right(1) + '|' + right(2) + '|' + back(0) + '|' + back(1) + '|' + back(2) + "|\n" +
      '|' + left(3) + '|' + left(4) + '|' + left(5) + '|' + front(3) + '|' + front(4) + '|' + front(5) +
      '|' + right(3) + '|' + right(4) + '|' + right(5) + '|' + back(3) + '|' + back(4) + '|' + back(5) + "|\n" +
      '|' + left(6) + '|' + left(7) + '|' + left(8) + '|' + front(6) + '|' + front(7) + '|' + front(8) +
      '|' + right(6) + '|' + right(7) + '|' + right(8) + '|' + back(6) + '|' + back(7) + '|' + back(8) + "|\n" +
      "|----|----|----|" + down(0) + '|' + down(1) + '|' + down(2) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + down(3) + '|' + down(4) + '|' + down(5) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + down(6) + '|' + down(7) + '|' + down(8) + "|----|----|----|----|----|----|"
    println(str)
  }
  def show_rubic_element_states(): Unit = {
    val up = side_up.getElemState
    val left = side_left.getElemState
    val front = side_front.getElemState
    val right = side_right.getElemState
    val back = side_back.getElemState
    val down = side_down.getElemState
    val str = "|----|----|----|" + cNS(up._1.toString) + '|' + cNS(up._2.toString) + '|' + cNS(up._3.toString) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + cNS(up._4.toString) + '|' + cNS(up._5.toString) + '|' + cNS(up._6.toString) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + cNS(up._7.toString) + '|' + cNS(up._8.toString) + '|' + cNS(up._9.toString) + "|----|----|----|----|----|----|" + '\n' +
      '|' + cNS(left._1.toString) + '|' + cNS(left._2.toString) + '|' + cNS(left._3.toString) + '|' + cNS(front._1.toString) + '|' + cNS(front._2.toString) + '|' + cNS(front._3.toString) +
      '|' + cNS(right._1.toString) + '|' + cNS(right._2.toString) + '|' + cNS(right._3.toString) + '|' + cNS(back._1.toString) + '|' + cNS(back._2.toString) + '|' + cNS(back._3.toString) + "|\n" +
      '|' + cNS(left._4.toString) + '|' + cNS(left._5.toString) + '|' + cNS(left._6.toString) + '|' + cNS(front._4.toString) + '|' + cNS(front._5.toString) + '|' + cNS(front._6.toString) +
      '|' + cNS(right._4.toString) + '|' + cNS(right._5.toString) + '|' + cNS(right._6.toString) + '|' + cNS(back._4.toString) + '|' + cNS(back._5.toString) + '|' + cNS(back._6.toString) + "|\n" +
      '|' + cNS(left._7.toString) + '|' + cNS(left._8.toString) + '|' + cNS(left._9.toString) + '|' + cNS(front._7.toString) + '|' + cNS(front._8.toString) + '|' + cNS(front._9.toString) +
      '|' + cNS(right._7.toString) + '|' + cNS(right._8.toString) + '|' + cNS(right._9.toString) + '|' + cNS(back._7.toString) + '|' + cNS(back._8.toString) + '|' + cNS(back._9.toString) + "|\n" +
      "|----|----|----|" + cNS(down._1.toString) + '|' + cNS(down._2.toString) + '|' + cNS(down._3.toString) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + cNS(down._4.toString) + '|' + cNS(down._5.toString) + '|' + cNS(down._6.toString) + "|----|----|----|----|----|----|" + '\n' +
      "|----|----|----|" + cNS(down._7.toString) + '|' + cNS(down._8.toString) + '|' + cNS(down._9.toString) + "|----|----|----|----|----|----|"
    println(str)
  }
  def fixStartState(): Unit = allSteps += "#"
  def execSteps(step: Array[String], addStepSymbol: Boolean = true): Unit = {
//    println(s"execSteps start: ${step.mkString(", ")}")
    step.foreach{ step =>
//      println(s"next step: $step")
//      show_rubic_elements()
//      println("------")
//      show_rubic_element_states()
//      show_rubic_color()
//      println()
      //      show_steps()
//      println(s"$step angle_4: ${angle_4.getCurrentPos}, ${angle_4.getTargetPos}")
//      println(s"$step side_8: ${side_8.getCurrentPos}, ${side_8.getTargetPos}")
//      println(s"$step side_11: ${side_11.getCurrentPos}, ${side_11.getTargetPos}")
      step match {
        case "F" => F_front(addStepSymbol)
        case "F'" => F_back(addStepSymbol)
        case "F2" => F_front_double(addStepSymbol)
        case "F2'" => F_back_double(addStepSymbol)
        case "U" => U_front(addStepSymbol)
        case "U'" => U_back(addStepSymbol)
        case "U2" => U_front_double(addStepSymbol)
        case "U2'" => U_back_double(addStepSymbol)
        case "D" => D_front(addStepSymbol)
        case "D'" => D_back(addStepSymbol)
        case "D2" => D_front_double(addStepSymbol)
        case "D2'" => D_back_double(addStepSymbol)
        case "R" => R_front(addStepSymbol)
        case "R'" => R_back(addStepSymbol)
        case "R2" => R_front_double(addStepSymbol)
        case "R2'" => R_back_double(addStepSymbol)
        case "L" => L_front(addStepSymbol)
        case "L'" => L_back(addStepSymbol)
        case "L2" => L_front_double(addStepSymbol)
        case "L2'" => L_back_double(addStepSymbol)
        case "B" => B_front(addStepSymbol)
        case "B'" => B_back(addStepSymbol)
        case "B2" => B_front_double(addStepSymbol)
        case "B2'" => B_back_double(addStepSymbol)
        case "x" => x_front(addStepSymbol)
        case "x2" => x_front(addStepSymbol); x_front(addStepSymbol)
        case "x'" => x_back(addStepSymbol)
        case "y" => y_front(addStepSymbol)
        case "y2" => y_front(addStepSymbol); y_front(addStepSymbol)
        case "y'" => y_back(addStepSymbol)
        case "z" => z_front(addStepSymbol)
        case "z2" => z_front(addStepSymbol); z_front(addStepSymbol)
        case "z'" => z_back(addStepSymbol)
        case "" =>
      }
//      println("after:")
//      show_rubic_elements()
//      println("------")
//      show_rubic_element_states()
//      show_rubic_color()
//      println()
    }
//    println(s"after side_8: ${side_8.getCurrentPos}, ${side_8.getTargetPos}")
//    show_rubic_elements()
//    println()
//    show_rubic_element_states()
//    println()
//    show_rubic_color()
  }

  private def getOnTopOfSide(startSide: Side): Side = {
    startSide.getPosition match {
      case Side_position.up => side_back
      case Side_position.left => side_up
      case Side_position.front => side_up
      case Side_position.right => side_up
      case Side_position.back => side_up
      case Side_position.down => side_front
    }
  }
  private def getOnLeftOfSide(startSide: Side): Side = {
    startSide.getPosition match {
      case Side_position.up => side_left
      case Side_position.left => side_back
      case Side_position.front => side_left
      case Side_position.right => side_front
      case Side_position.back => side_right
      case Side_position.down => side_left
    }
  }
  private def getOnDownOfSide(startSide: Side): Side = {
    startSide.getPosition match {
      case Side_position.up => side_front
      case Side_position.left => side_down
      case Side_position.front => side_down
      case Side_position.right => side_down
      case Side_position.back => side_down
      case Side_position.down => side_back
    }
  }
  private def getOnRightOfSide(startSide: Side): Side = {
    startSide.getPosition match {
      case Side_position.up => side_right
      case Side_position.left => side_front
      case Side_position.front => side_right
      case Side_position.right => side_back
      case Side_position.back => side_left
      case Side_position.down => side_right
    }
  }
  private def checkSecondLayerComplete(startSide: Side): Boolean = {
    val onTopOf: Side = getOnTopOfSide(startSide)
    val onLeftOf: Side = getOnLeftOfSide(startSide)
    val onDownOf: Side = getOnDownOfSide(startSide)
    val onRightOf: Side = getOnRightOfSide(startSide)
    if (onTopOf.checkSecondLayerComplete(startSide.getPosition)
      && onLeftOf.checkSecondLayerComplete(startSide.getPosition)
      && onDownOf.checkSecondLayerComplete(startSide.getPosition)
      && onRightOf.checkSecondLayerComplete(startSide.getPosition))
      true
    else
      false
  }
  private def getOppositeSide(startSide: Side): Side = {
    startSide.getPosition match {
      case Side_position.up => side_down
      case Side_position.left => side_right
      case Side_position.front => side_back
      case Side_position.right => side_left
      case Side_position.back => side_front
      case Side_position.down => side_up
    }
  }
  private def getOppositeSideStateAfterCrestComplete(oppositeSide: Side): (OppositeState, Array[String]) = {
    oppositeSide.getStateForOppositeSide()
  }

  // Algorithm 1
  private def collect_crest(): Side = {
    val sideWithCompleteCrest = for (side <- all_sides.filter(side => side.checkCrest())) yield side
    if (sideWithCompleteCrest.length >= 1)
      sideWithCompleteCrest.head
    else {
      val startSide: (Side, (Side_composition, Side_position_with_rubic)) =
        (for (side <- all_sides) yield (side -> side.getStateCrest)).sortBy(_._2._1).head
//      println((for (side <- all_sides) yield (side -> side.getStateCrest)).sortBy(_._2._1).mkString)
//      println(s"start side = ${startSide._1.getPosition.toString}")
      startSide._2._2 match {
        case Side_position_with_rubic.p_zero => ()
        case Side_position_with_rubic.p_one_u => execSteps(Array("U"))//U_front()
        case Side_position_with_rubic.p_two_u => execSteps(Array("U2"))//U_front_double()
        case Side_position_with_rubic.p_one_ub => execSteps(Array("U'"))//U_back()
        case Side_position_with_rubic.p_one_l => execSteps(Array("L"))//L_front()
        case Side_position_with_rubic.p_two_l => execSteps(Array("L2"))//L_front_double()
        case Side_position_with_rubic.p_one_lb => execSteps(Array("L'"))//L_back()
        case Side_position_with_rubic.p_one_f => execSteps(Array("F"))//F_front()
        case Side_position_with_rubic.p_two_f => execSteps(Array("F2"))//F_front_double()
        case Side_position_with_rubic.p_one_fb => execSteps(Array("F'"))//F_back()
        case Side_position_with_rubic.p_one_r => execSteps(Array("R"))//R_front()
        case Side_position_with_rubic.p_two_r => execSteps(Array("R2"))//R_front_double()
        case Side_position_with_rubic.p_one_rb => execSteps(Array("R'"))//R_back()
        case Side_position_with_rubic.p_one_b => execSteps(Array("B"))//B_front()
        case Side_position_with_rubic.p_two_b => execSteps(Array("B2"))//B_front_double()
        case Side_position_with_rubic.p_one_bb => execSteps(Array("B'"))//B_back()
        case Side_position_with_rubic.p_one_d => execSteps(Array("D"))//D_front()
        case Side_position_with_rubic.p_two_d => execSteps(Array("F2"))//F_front_double()
        case Side_position_with_rubic.p_one_db => execSteps(Array("D'"))//D_back()
      }
      while (!startSide._1.checkCrest()) {
        val nextElem = getNextRequiredSideElemForFirstLayer(startSide._1)
//        println(s"nextElem: ${nextElem.getName}, ${nextElem.getTargetPos}, ${nextElem.getCurrentPos}")
        val targetPos = nextElem.target_pos
        val currentPos = searchSideElemInRubic(targetPos).getCurrentPos
        val neededMovies = getNeededMoviesForSideFirstLayer(currentPos, targetPos, startSide._1.getPosition)
        execSteps(neededMovies)
      }
//      show_rubic_color()
//      println(s"collect cross finish")
//      show_rubic_elements()
//      show_rubic_element_states()
//      println()
      startSide._1
      //      while (startState.)
      // + 1. Get start position
      // 2. Get next elem position
      // 3. Create way to this elem to the its final position
      // 4. Move the way
      // 5. Check crest complete
      // 6. If complete return else go to step 2
    }
  }
  private def collect_first_layer(startSide: Side): Unit = {
    while (!startSide.checkFullComplete()) {
      val nextElem = getNextRequiredAngleElemForFirstLayer(startSide)
//      println(s"collect_first_layer nextElem: ${nextElem.getName}, ${nextElem.getTargetPos}, ${nextElem.getCurrentPos}")
//      show_rubic_color()
//      show_rubic_elements()
//      show_rubic_element_states()
      val targetPos = nextElem.target_pos
//      println(s"collect_first_layer: target pos = ${targetPos.toString}")
      val currentPos = searchAngleElemInRubic(targetPos).getCurrentPos
//      println(s"collect_first_layer: current pos = ${currentPos.toString}")
      val neededMovies = getNeededMoviesForAngleFirstLayer(currentPos, targetPos, startSide.getPosition)
//      println(s"collect_first_layer: needed movies = ${neededMovies.mkString}")
      execSteps(neededMovies)
    }
  }
  private def collect_second_layer(startSide: Side): Unit = {
    while (!checkSecondLayerComplete(startSide)) {
      val nextElem = getNextRequiredSideElemForSecondLayer(startSide)
//      println(s"collect_second_layer nextElem: ${nextElem.getName}, ${nextElem.getTargetPos}, ${nextElem.getCurrentPos}")
//      show_rubic_color()
//      show_rubic_elements()
//      show_rubic_element_states()
      val targetPos = reversePositionForFinalStateSideElem(nextElem.getCurrentPos) //nextElem.target_pos
//      println(s"collect_second_layer: target pos = ${targetPos.toString}")
      val currentPos = searchSideElemInRubic(targetPos).getCurrentPos
//      println(s"collect_second_layer: current pos = ${currentPos.toString}")
      val neededMovies = getNeededMoviesForSideSecondLayer(currentPos, targetPos, startSide.getPosition)
//      println(s"collect_second_layer: needed movies = ${neededMovies.mkString}")
      execSteps(neededMovies)
    }
  }
  private def collect_second_crest(startSide: Side): Side = {
    val rightSide = getOppositeSide(startSide)
    while (!rightSide.checkCrestOnlyOneColor(rightSide.getPosition)) {
      val steps = getNeededMoviesForOppositeSideCrestFirst(rightSide.getPosition)
      println(s"collect_second_crest: ${steps.mkString}")
      execSteps(steps)
      show_rubic_color()
    }
    rightSide
//    while (rightSide.checkCrest()) {
//      val nextElem = rightSide.getNextRequiredSideElemForSecondCrestFinalStep
//      val targetPos = nextElem.target_pos
//      val currentPos = searchSideElemInRubic(targetPos)
//      val neededMovies = getNeededMoviesForOppositeSideCrestFinal(currentPos, targetPos, rightSide.getPosition)
//      execSteps(neededMovies)
//    }
    // 1. get opposite side
    // 2. until the crest not complete
    // 3. get next elem
    // 4. get needed steps
    // 5. do steps
    // 6. go to point 2
  }
  private def collect_second_side(oppositeSide: Side): Unit = {
    val combo_1 = Array("R'", "U2", "R", "U", "R'", "U", "R")
    val combo_2 = Array("U'", "R", "U2", "R'", "U'", "R", "U'", "R")
    while (!oppositeSide.checkCOLL_Complete()) {
      show_rubic_color()
      println(s"collect_second_side start: opposite side: ${oppositeSide.getPosition}")
      val stateAndMaybeSteps = getOppositeSideStateAfterCrestComplete(oppositeSide)
      println(s"collect_second_side received steps: ${stateAndMaybeSteps._2.mkString}")
      execSteps(stateAndMaybeSteps._2)
      stateAndMaybeSteps._1 match {
        case OppositeState.opp_one => execSteps(combo_1)
        case OppositeState.opp_two => execSteps(combo_2)
        case OppositeState.opp_three => execSteps(combo_1 ++ combo_2)
        case OppositeState.opp_four => execSteps(combo_2 ++ combo_2)
        case OppositeState.opp_five => execSteps(combo_2 ++ combo_1)
        case OppositeState.opp_six => execSteps(combo_1 ++ Array("U'") ++ combo_1)
        case OppositeState.opp_seven => execSteps(combo_2 ++ Array("U2") ++ combo_1)
      }
    }
  }
  private def collect_angles(): Unit = ???
  private def collect_all(): Unit = ???

  def collect_rubic(): Unit = {
    // Algorithm
    // 1 этап — сборка правильного креста
    val startSide = collect_crest()
    println(s"Collect_crest complete: start side = ${startSide.getPosition.toString}")
    show_rubic_color()
//    show_rubic_elements()
//    show_rubic_element_states()

    // 2 этап — сборка первого слоя
    collect_first_layer(startSide)
    println(s"collect_first_layer complete")
    show_rubic_color()
//    show_rubic_elements()
//    show_rubic_element_states()

    // 3 этап — сборка второго слоя
    collect_second_layer(startSide)
    println(s"collect_second_layer complete")
    show_rubic_color()
//    show_rubic_elements()
//    show_rubic_element_states()

    // 4 этап — сборка креста сверху
    val oppositeSide = collect_second_crest(startSide)
    println(s"collect_second_crest complete: opposite side: ${oppositeSide.getPosition.toString}")
    show_rubic_color()
//    show_rubic_elements()
//    show_rubic_element_states()

    // 5 этап — cборка верхней стороны
    collect_second_side(oppositeSide)
//    println(s"collect_second_side complete")
//    show_rubic_color()
//    show_rubic_elements()
//    show_rubic_element_states()

    // 6 этап — расстановка ребер
//    collect_angles()
    // 7 этап — перестановка углов
//    collect_all()
    println(s"COLLECT FINISH")
  }

  private def getOtherSides(startSide: Side): Array[Side] = {
    startSide match {
      case Side_position.up => Array(side_down, side_left, side_front, side_right, side_back)
      case Side_position.left => Array(side_right, side_up, side_back, side_down, side_front)
      case Side_position.front => Array(side_back, side_up, side_right, side_down, side_left)
      case Side_position.right => Array(side_left, side_up, side_back, side_down, side_front)
      case Side_position.back => Array(side_front, side_up, side_right, side_down, side_left)
      case Side_position.down => Array(side_up, side_left, side_front, side_right, side_back)
    }
  }
  private def getTargetSides(startSide: Side, otherSides: Array[Side]): (Side, Side) = {
    val retArr = (for (i <- 1 to 5)
      yield (otherSides(i), otherSides(if (i < 5) i + 1 else 1),
        otherSides(i).checkFridrihF2L(startSide.getPosition, otherSides(if (i < 5) i + 1 else 1).getPosition)
      )).filter(elem => !elem._3)
    (retArr.head._1, retArr.head._2)
  }
  private def getTargetAngleElemF2L(): Elem_angle = {
    searchAngleElemInRubic(fdr1)
//    side_front.getRightDownElem()
  }
  private def getTargetSideElemF2L(): Elem_side = {
    searchSideElemInRubic(fr1)
//    side_front.getCenterRightElem()
  }

  private def getStepsForFridrihF2L(): Array[String] = {
//    println(s"getStepsForFridrihF2L start")
//    show_rubic_element_states()
    // 1. Check current state for F2L complete
    //    1.1 Ok
    //      1.1.1 Return F2L state
    //    1.2 Need movies
    //      1.2.1 Do movies
    //      1.2.2 Go to step 1

    val targetPositionsAngleElem = Array(
      Angle_elem_position.fdr1,
      Angle_elem_position.fdr2,
      Angle_elem_position.fdr3,
      Angle_elem_position.fur1,
      Angle_elem_position.fur2,
      Angle_elem_position.fur3,
      Angle_elem_position.ful1,
      Angle_elem_position.ful2,
      Angle_elem_position.ful3,
      Angle_elem_position.bur1,
      Angle_elem_position.bur2,
      Angle_elem_position.bur3,
      Angle_elem_position.bul1,
      Angle_elem_position.bul2,
      Angle_elem_position.bul3
    )
    val targetPositionsSideElem = Array(
      Side_elem_position.fr1,
      Side_elem_position.fr2,
      Side_elem_position.fu1,
      Side_elem_position.fu2,
      Side_elem_position.lu1,
      Side_elem_position.lu2,
      Side_elem_position.bu1,
      Side_elem_position.bu2,
      Side_elem_position.ru1,
      Side_elem_position.ru2,
    )
    val targetAngleElem = getTargetAngleElemF2L()
    val targetSideElem = getTargetSideElemF2L()
    while (!targetPositionsAngleElem.contains(targetAngleElem.getCurrentPos) ||
      !targetPositionsSideElem.contains(targetSideElem.getCurrentPos)) {
      if (!targetPositionsAngleElem.contains(targetAngleElem.getCurrentPos)) {
        val stepsForAngleElem = collectionAngleMoviesForPrepareF2L(targetAngleElem.getCurrentPos)
        execSteps(stepsForAngleElem)
      }
      if (!targetPositionsSideElem.contains(targetSideElem.getCurrentPos)) {
        val stepsForSideElem = collectionSideMoviesForPrapareF2L(targetSideElem.getCurrentPos)
        execSteps(stepsForSideElem)
      }
    }
//    println(s"getStepsForFridrihF2L: ${targetAngleElem.getName} ${targetSideElem.getName}" +
//      s"\n${targetAngleElem.getCurrentPos}|${targetAngleElem.getTargetPos}" +
//      s"\n${targetSideElem.getCurrentPos}|${targetSideElem.getTargetPos}")
    collectionMoviesForF2L(targetAngleElem.getCurrentPos, targetSideElem.getCurrentPos)
//    println(s"getStepsForFridrihF2L finish ${rr.length} ${rr.mkString(", ")}")
//    rr
  }
  private def getStateForFridrihOLL(startSide: Side): State_for_Fridrih_OLL = {
//    startSide match {
//      case Side_position.up =>
//      case Side_position.left =>
//      case Side_position.front =>
//      case Side_position.right =>
//      case Side_position.back =>
//      case Side_position.down =>
//    }
    ???
  }
  private def getStateForFridrihPLL(startSide: Side): State_for_Fridrih_PLL = {
    //    startSide match {
    //      case Side_position.up =>
    //      case Side_position.left =>
    //      case Side_position.front =>
    //      case Side_position.right =>
    //      case Side_position.back =>
    //      case Side_position.down =>
    //    }
    ???
  }

  private def getStepsForFridrihOLL(state: State_for_Fridrih_OLL): Array[String] = {
    ???
  }
  private def getStepsForFridrihPLL(state: State_for_Fridrih_PLL): Array[String] = {
    ???
  }

  private def fridrihF2L(startSide: Side): Unit = {
//    println(s"fridrihF2L start")
//    show_rubic_elements()
//    show_rubic_element_states()
//    var ff = true
//    var sideNumberCheck = 0
    for (_ <- 0 to 3) {
//      val steps = getStepsForFridrihF2L()
//      show_rubic_element_states()
//      show_rubic_elements()
//      println()
      execSteps(getStepsForFridrihF2L())
//      println(s"fridrih f2l next iter: ${steps.mkString(", ")}")
//      execSteps(steps)
//      ff = steps.length > 1
//      println(s"y_front pre:")
//      show_rubic_element_states()
//      show_rubic_elements()
//      println()
//      y_front(false)
      execSteps(Array("y"))
//      show_rubic_elements()
//      println(s"y_front after:")
//      show_rubic_element_states()
//      show_rubic_elements()
      //      sideNumberCheck += 1
    }
//    show_rubic_color()
  }
  private def fridrihOLL(startSide: Side): Unit = {
    while (true) {
      val state = getStateForFridrihOLL(startSide) // get state for second step Fridrih method
      val steps = getStepsForFridrihOLL(state) // get formula for down start side only
      execSteps(steps)
    }
  }
  private def fridrihPLL(startSide: Side): Unit = {
    while (true) {
      val state = getStateForFridrihPLL(startSide) // get state for second step Fridrih method
      val steps = getStepsForFridrihPLL(state) // get formula for down start side only
      execSteps(steps)
    }
  }
  private def changeStartSide(startSide: Side): Side = {
//    println(s"changeStartSide start ${startSide.getPosition}")
//    show_rubic_element_states()
    startSide.getPosition match {
      case Side_position.up =>
//        println("x_front2")
        execSteps(Array("x", "x"))// x_front()
//        x_front()
      case Side_position.left =>
//        println("z_back")
        execSteps(Array("z'"))//z_back()
      case Side_position.front =>
//        println("x_back")
        execSteps(Array("x'"))//x_back()
      case Side_position.right =>
//        println("z_front")
        execSteps(Array("z"))//z_front()
      case Side_position.back =>
//        println("x_front")
        execSteps(Array("x"))//x_front()
      case Side_position.down =>
    }
//    println(s"changeStartSide finish")
//    show_rubic_element_states()
    side_down
  }
  private def oppositeCross(): Unit = {
    val upElems = side_up.getAllElems()
//    println(s"oppositeCross: \n${upElems._8.getName}|${upElems._8.getCurrentPos}, ${upElems._4.getName}|${upElems._4.getCurrentPos}, " +
//      s"${upElems._2.getName}|${upElems._2.getCurrentPos}, ${upElems._6.getName}|${upElems._6.getCurrentPos}")
    val movies = collectionOppositeCrossAfterF2L((upElems._8.getCurrentPos,
      upElems._4.getCurrentPos, upElems._2.getCurrentPos, upElems._6.getCurrentPos))
    execSteps(movies)
  }
  private def COLL(): Unit = {
    if (!side_up.checkCOLL_Complete()) {
//      println(s"###########COLL START##############")
//      show_rubic_element_states()
//      show_rubic_elements()
//      println()
      var p = 1
      var ss = true
      var steps = collectionCOLL(p)
      execSteps(steps, false)
      while(ss && p < collectionCOLL.size){
        if (side_up.checkCOLL_Complete()){
          ss = false
          execSteps(collectionCOLL(p + 1).reverse, false) // reverse previous steps
        } else {
          p += 1
          execSteps(collectionCOLL(p).reverse, false) // reverse previous steps
          if (p < collectionCOLL.size) {
            p += 1
            steps = collectionCOLL(p)
            execSteps(steps, false)
          } else {
            ss = false
//            println("COLL: Don't needed formula")
          }
        }
      }
      if (!(p == collectionCOLL.size)) {
        execSteps(steps)
      }
//      show_rubic_element_states()
    }
  }
  private def PLL(): Unit = {
    if (!side_up.checkFullComplete()) {
//      println(s"###########PLL START##############")
//      show_rubic_element_states()
//      show_rubic_elements()
//      println()
      var p = 1
      var ss = true
      var steps = collectionPLL(p)
      val afterFail = Array("")
      execSteps(steps, false)
      while (ss && p < collectionPLL.size) {
//        println(s"Cycle interation next")
        if (side_up.checkFullComplete() &&
              side_left.checkFullComplete() &&
              side_front.checkFullComplete() &&
              side_right.checkFullComplete() &&
              side_back.checkFullComplete() &&
              side_down.checkFullComplete()) {
//          println(s"COMPLETE PLL")
          ss = false
          execSteps(collectionPLL(p + 1).reverse, false) // reverse previous steps
//          show_rubic_element_states()
//          show_rubic_elements()
//          println()
        } else {
          p += 1
          execSteps(collectionPLL(p).reverse, false) // reverse previous steps
//          show_rubic_element_states()
//          show_rubic_elements()
//          println()
          if (p < collectionPLL.size) {
            p += 1
//            if (p == 243) {
//              show_rubic_element_states()
//              show_rubic_elements()
//              println()
//            }
            steps = collectionPLL(p)
            execSteps(steps, false)
//            if (p == 243) {
//              show_rubic_element_states()
//              show_rubic_elements()
//              println()
//            }
          } else {
//            if (afterFail(0) == "") {
//              afterFail(0) = "U"
//              execSteps(afterFail)
//              show_rubic_element_states()
//              show_rubic_elements()
//              p = 1
//              steps = collectionPLL(p)
//              execSteps(steps, false)
//            } else if (afterFail(0) == "U") {
//              execSteps(afterFail)
//              afterFail(0) = "U'"
//              p = 1
//              steps = collectionPLL(p)
//              execSteps(steps, false)
//            } else if (afterFail(0) == "U'") {
//              execSteps(Array("U"))
//              afterFail(0) = "U2"
//              p = 1
//              steps = collectionPLL(p)
//              execSteps(steps, false)
//            } else {
              ss = false
//              println("PLL: Don't needed formula")
//            }
          }
        }
      }
      if (!(p == collectionPLL.size)) {
        execSteps(steps)
//        show_rubic_elements()
//        show_rubic_element_states()
      }
    }
  }

  def collect_two(): Unit = {
    /*
    1. Collect cross
      +
    2. Collect first side
      +
    3. Collect second layer
      a) U' L' U' L U y' R U R' U'
      b) U R U R' U' y L' U' L U

    4. Collect second cross
      a) F R U R' U' F'
      b) F R U R' U' R U R' U' F'
      c) F R U R' U' F'  U2  F R U R' U' R U R' U' F'

    5. Collect opposite side
      a) R U R' U' R U R' U'
      b) R U R' U' R U R' U' R U R' U' R U R' U'

    6. Change side elems
      a) R U R' F' R U R' U' R' F R2 U' R' U'
      b) R U R' F' R U R' U' R' F R2 U' R' U'  U2  R U R' F' R U R' U' R' F R2 U' R' U'  U'

    7. Install all angles colors
      a) U2 R U2 R’ F2 U2 L’ U2 L F2 * n
     */
//    println(s"collect_two 1")
//    show_rubic_color()
//    show_rubic_elements()
//    show_steps()
//    show_rubic_element_states()
    val startSide = changeStartSide(collect_crest())
//    fixStartState()

//    show_rubic_color()
//    println(s"collect_two 2")
//    show_rubic_element_states()
//    show_steps()
//    show_rubic_elements()
//    show_rubic_color()
    fridrihF2L(startSide)
//    fixStartState()

//    println(s"collect_two 3")
    oppositeCross()
//    fixStartState()

//    println(s"collect_two 4")
    if (!side_up.checkCOLL_CompleteOnlyColor()) // If opposite side color complete
      COLL()
    if (!side_up.checkCOLL_CompleteOnlyColor()) {
//      println("ONE++++++++++++++++++++++++++++++")
      execSteps(Array("U"))
      COLL()
    }
    if (!side_up.checkCOLL_CompleteOnlyColor()) {
//      println("TWO++++++++++++++++++++++++++++++")
      execSteps(Array("U"))
      COLL()
    }
    if (!side_up.checkCOLL_CompleteOnlyColor()) {
//      println("THREE++++++++++++++++++++++++++++++")
      execSteps(Array("U"))
      COLL()
    }
    if (!side_up.checkCOLL_CompleteOnlyColor())
      println("COLL: Don't needed formula")
    //    fixStartState()
//    collect_second_side(side_up)

//    println(s"collect_two 5")
//    show_rubic_elements()
//    println("-------------")
//    show_rubic_element_states()
//    println()

    PLL()
    if (!side_up.checkFullComplete()) {
//      println("ONE=================================")
      execSteps(Array("U"))
      PLL()
    }
    if (!side_up.checkFullComplete()) {
//      println("TWO=================================")
      execSteps(Array("U"))
      PLL()
    }
    if (!side_up.checkFullComplete()) {
//      println("THRE=================================")
      execSteps(Array("U"))
      PLL()
    }
    if (!side_up.checkFullComplete())
      println("PLL: Don't needed formula")
//    show_rubic_elements()
//    println("-------------")
//    show_rubic_element_states()
//    println()
//    fixStartState()
//    show_rubic_color()
//    show_steps()
//    fridrihOLL(startSide)
//    fridrihPLL(startSide)
  }

  private def changeColorSeq_x(): Unit = {
    // front -> up
    val up = colorSequence(0)
    val left = colorSequence(1)
    val front = colorSequence(2)
    val right = colorSequence(3)
    val back = colorSequence(4)
    val down = colorSequence(5)
    colorSequence(0) = front
    colorSequence(1) = left
    colorSequence(2) = down
    colorSequence(3) = right
    colorSequence(4) = up
    colorSequence(5) = back
  }
  private def changeColorSeq_xb(): Unit = {
    // front -> down
    val up = colorSequence(0)
    val left = colorSequence(1)
    val front = colorSequence(2)
    val right = colorSequence(3)
    val back = colorSequence(4)
    val down = colorSequence(5)
    colorSequence(0) = back
    colorSequence(1) = left
    colorSequence(2) = up
    colorSequence(3) = right
    colorSequence(4) = down
    colorSequence(5) = front
  }
  private def changeColorSeq_y(): Unit = {
    // front -> left
    val up = colorSequence(0)
    val left = colorSequence(1)
    val front = colorSequence(2)
    val right = colorSequence(3)
    val back = colorSequence(4)
    val down = colorSequence(5)
    colorSequence(0) = up
    colorSequence(1) = front
    colorSequence(2) = right
    colorSequence(3) = back
    colorSequence(4) = left
    colorSequence(5) = down
  }
  private def changeColorSeq_yb(): Unit = {
    // front -> right
    val up = colorSequence(0)
    val left = colorSequence(1)
    val front = colorSequence(2)
    val right = colorSequence(3)
    val back = colorSequence(4)
    val down = colorSequence(5)
    colorSequence(0) = up
    colorSequence(1) = back
    colorSequence(2) = left
    colorSequence(3) = front
    colorSequence(4) = right
    colorSequence(5) = down
  }
  private def changeColorSeq_z(): Unit = {
    // up -> right
    val up = colorSequence(0)
    val left = colorSequence(1)
    val front = colorSequence(2)
    val right = colorSequence(3)
    val back = colorSequence(4)
    val down = colorSequence(5)
    colorSequence(0) = left
    colorSequence(1) = down
    colorSequence(2) = front
    colorSequence(3) = up
    colorSequence(4) = back
    colorSequence(5) = right
  }
  private def changeColorSeq_zb(): Unit = {
    // up -> left
    val up = colorSequence(0)
    val left = colorSequence(1)
    val front = colorSequence(2)
    val right = colorSequence(3)
    val back = colorSequence(4)
    val down = colorSequence(5)
    colorSequence(0) = right
    colorSequence(1) = up
    colorSequence(2) = front
    colorSequence(3) = down
    colorSequence(4) = back
    colorSequence(5) = left
  }
  private class AbstractRubic() {
    private val rub = Array("U", "L", "F", "R", "B", "D")

    def x_f(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = front
      rub(1) = left
      rub(2) = down
      rub(3) = right
      rub(4) = up
      rub(5) = back
    }
    def x_b(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = back
      rub(1) = left
      rub(2) = up
      rub(3) = right
      rub(4) = down
      rub(5) = front
    }
    def x_f2(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = down
      rub(1) = left
      rub(2) = back
      rub(3) = right
      rub(4) = front
      rub(5) = up
    }
    def y_f(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = up
      rub(1) = front
      rub(2) = right
      rub(3) = back
      rub(4) = left
      rub(5) = down
    }
    def y_b(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = up
      rub(1) = back
      rub(2) = left
      rub(3) = front
      rub(4) = right
      rub(5) = down
    }
    def y_f2(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = up
      rub(1) = right
      rub(2) = back
      rub(3) = left
      rub(4) = front
      rub(5) = down
    }
    def z_f(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = left
      rub(1) = down
      rub(2) = front
      rub(3) = up
      rub(4) = back
      rub(5) = right
    }
    def z_b(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = right
      rub(1) = up
      rub(2) = front
      rub(3) = down
      rub(4) = back
      rub(5) = left
    }
    def z_f2(): Unit = {
      val up = rub(0)
      val left = rub(1)
      val front = rub(2)
      val right = rub(3)
      val back = rub(4)
      val down = rub(5)

      rub(0) = down
      rub(1) = right
      rub(2) = front
      rub(3) = left
      rub(4) = back
      rub(5) = up
    }
    def getUp(): String = rub(0)
    def getLeft(): String = rub(1)
    def getFront(): String = rub(2)
    def getRight(): String = rub(3)
    def getBack(): String = rub(4)
    def getDown(): String = rub(5)
  }
  private def modifyStep(rub: AbstractRubic, step: String): String = {
//    println(s"modifyStep start: step = $step")
    var ret = step
    step match {
      case "U" => ret = rub.getUp()
      case "U'" => ret = rub.getUp().concat("'")
      case "U2" => ret = rub.getUp().concat("2")
      case "L" => ret = rub.getLeft()
      case "L'" => ret = rub.getLeft().concat("'")
      case "L2" => ret = rub.getLeft().concat("2")
      case "F" => ret = rub.getFront()
      case "F'" => ret = rub.getFront().concat("'")
      case "F2" => ret = rub.getFront().concat("2")
      case "R" => ret = rub.getRight()
      case "R'" => ret = rub.getRight().concat("'")
      case "R2" => ret = rub.getRight().concat("2")
      case "B" => ret = rub.getBack()
      case "B'" => ret = rub.getBack().concat("'")
      case "B2" => ret = rub.getBack().concat("2")
      case "D" => ret = rub.getDown()
      case "D'" => ret = rub.getDown().concat("'")
      case "D2" => ret = rub.getDown().concat("2")
      case _ =>
    }
//    println(s"ret step = $ret")
    ret
  }
  private def prepareAllSteps(): Unit = {
    // remove all movies: x, y, z ....
    // remove double and fictitious steps
    val arrBuff = ArrayBuffer[String]()
    val rub = new AbstractRubic()
    val deleteIndices = for (i <- allSteps.indices if (
      allSteps(i) == "x" ||
        allSteps(i) == "x'" ||
        allSteps(i) == "x2" ||
        allSteps(i) == "y" ||
        allSteps(i) == "y'" ||
        allSteps(i) == "y2" ||
        allSteps(i) == "z" ||
        allSteps(i) == "z'" ||
        allSteps(i) == "z2")) yield i
//    println(s"${deleteIndices.mkString(", ")}")
    for (i <- allSteps.indices) {
      allSteps(i) match {
        case "x" => rub.x_f()
        case "x'" => rub.x_b()
        case "x2" => rub.x_f2()
        case "y" => rub.y_f()
        case "y'" => rub.y_b()
        case "y2" => rub.y_f2()
        case "z" => rub.z_f()
        case "z'" => rub.z_b()
        case "z2" => rub.z_f2()
        case _ => allSteps(i) = modifyStep(rub, allSteps(i))
      }
    }
    for (i <- deleteIndices.sorted.reverse) allSteps.remove(i)
    val deleteSteps = new ArrayBuffer[Int]
    for (i <- 1 until allSteps.size) {
      allSteps(i) match {
        case "U" =>
          allSteps(i - 1) match {
            case "U" => allSteps(i) = "U2"; deleteSteps += i - 1
            case "U'" => deleteSteps += i; deleteSteps += i - 1
            case "U2" => allSteps(i) = "U'"; deleteSteps += i - 1
            case _ =>
          }
        case "U'" =>
          allSteps(i - 1) match {
            case "U" => deleteSteps += i; deleteSteps += i - 1
            case "U'" => allSteps(i) = "U2"; deleteSteps += i - 1
            case "U2" => allSteps(i) = "U"; deleteSteps += i - 1
            case _ =>
          }
        case "U2" =>
          allSteps(i - 1) match {
            case "U" => allSteps(i) = "U'"; deleteSteps += i - 1
            case "U'" => allSteps(i) = "U"; deleteSteps += i - 1
            case "U2" => deleteSteps += i; deleteSteps += i - 1
            case _ =>
          }
        case "L" =>
          allSteps(i - 1) match {
            case "L" => allSteps(i) = "L2"; deleteSteps += i - 1
            case "L'" => deleteSteps += i; deleteSteps += i - 1
            case "L2" => allSteps(i) = "L'"; deleteSteps += i - 1
            case _ =>
          }
        case "L'" =>
          allSteps(i - 1) match {
            case "L" => deleteSteps += i; deleteSteps += i - 1
            case "L'" => allSteps(i) = "L2"; deleteSteps += i - 1
            case "L2" => allSteps(i) = "L"; deleteSteps += i - 1
            case _ =>
          }
        case "L2" =>
          allSteps(i - 1) match {
            case "L" => allSteps(i) = "L'"; deleteSteps += i - 1
            case "L'" => allSteps(i) = "L"; deleteSteps += i - 1
            case "L2" => deleteSteps += i; deleteSteps += i - 1
            case _ =>
          }
        case "F" =>
          allSteps(i - 1) match {
            case "F" => allSteps(i) = "F2"; deleteSteps += i - 1
            case "F'" => deleteSteps += i; deleteSteps += i - 1
            case "F2" => allSteps(i) = "F'"; deleteSteps += i - 1
            case _ =>
          }
        case "F'" =>
          allSteps(i - 1) match {
            case "F" => deleteSteps += i; deleteSteps += i - 1
            case "F'" => allSteps(i) = "F2"; deleteSteps += i - 1
            case "F2" => allSteps(i) = "F"; deleteSteps += i - 1
            case _ =>
          }
        case "F2" =>
          allSteps(i - 1) match {
            case "F" => allSteps(i) = "F'"; deleteSteps += i - 1
            case "F'" => allSteps(i) = "F"; deleteSteps += i - 1
            case "F2" => deleteSteps += i; deleteSteps += i - 1
            case _ =>
          }
        case "R" =>
          allSteps(i - 1) match {
            case "R" => allSteps(i) = "R2"; deleteSteps += i - 1
            case "R'" => deleteSteps += i; deleteSteps += i - 1
            case "R2" => allSteps(i) = "R'"; deleteSteps += i - 1
            case _ =>
          }
        case "R'" =>
          allSteps(i - 1) match {
            case "R" => deleteSteps += i; deleteSteps += i - 1
            case "R'" => allSteps(i) = "R2"; deleteSteps += i - 1
            case "R2" => allSteps(i) = "R"; deleteSteps += i - 1
            case _ =>
          }
        case "R2" =>
          allSteps(i - 1) match {
            case "R" => allSteps(i) = "R'"; deleteSteps += i - 1
            case "R'" => allSteps(i) = "R"; deleteSteps += i - 1
            case "R2" => deleteSteps += i; deleteSteps += i - 1
            case _ =>
          }
        case "B" =>
          allSteps(i - 1) match {
            case "B" => allSteps(i) = "B2"; deleteSteps += i - 1
            case "B'" => deleteSteps += i; deleteSteps += i - 1
            case "B2" => allSteps(i) = "B'"; deleteSteps += i - 1
            case _ =>
          }
        case "B'" =>
          allSteps(i - 1) match {
            case "B" => deleteSteps += i; deleteSteps += i - 1
            case "B'" => allSteps(i) = "B2"; deleteSteps += i - 1
            case "B2" => allSteps(i) = "B"; deleteSteps += i - 1
            case _ =>
          }
        case "B2" =>
          allSteps(i - 1) match {
            case "B" => allSteps(i) = "B'"; deleteSteps += i - 1
            case "B'" => allSteps(i) = "B"; deleteSteps += i - 1
            case "B2" => deleteSteps += i; deleteSteps += i - 1
            case _ =>
          }
        case "D" =>
          allSteps(i - 1) match {
            case "D" => allSteps(i) = "D2"; deleteSteps += i - 1
            case "D'" => deleteSteps += i; deleteSteps += i - 1
            case "D2" => allSteps(i) = "D'"; deleteSteps += i - 1
            case _ =>
          }
        case "D'" =>
          allSteps(i - 1) match {
            case "D" => deleteSteps += i; deleteSteps += i - 1
            case "D'" => allSteps(i) = "D2"; deleteSteps += i - 1
            case "D2" => allSteps(i) = "D"; deleteSteps += i - 1
            case _ =>
          }
        case "D2" =>
          allSteps(i - 1) match {
            case "D" => allSteps(i) = "D'"; deleteSteps += i - 1
            case "D'" => allSteps(i) = "D"; deleteSteps += i - 1
            case "D2" => deleteSteps += i; deleteSteps += i - 1
            case _ =>
          }
        case _ =>
      }
    }
//    println(s" prepare finish ${deleteSteps.sorted.reverse.mkString(", ")}")
    for (i <- deleteSteps.sorted.reverse) {
//      println(s" i = $i; step: ${allSteps(i)}")
      allSteps.remove(i)
    }
  }

  def show_steps(): Unit = {
//    println(allSteps.mkString(" "))
    allSteps.remove(0, allSteps.indexOf("#") + 1)
    prepareAllSteps()
    println(s"        " + allSteps.mkString(" "))
//    println(s"size = ${allSteps.size}")
  }
  def x_front(addStepSymbol: Boolean = true): Unit = {
    // front -> up
    changeColorSeq_x()
    val upElems = side_up.getAllElems()
    val leftElems = side_left.getAllElems()
    val frontElems = side_front.getAllElems()
    val rightElems = side_right.getAllElems()
    val backElems = side_back.getAllElems()
    val downElems = side_down.getAllElems()

    side_up.x_front(frontElems)
    side_left.x_front(leftElems)
    side_front.x_front(downElems)
    side_right.x_front(rightElems)
    side_back.x_front(upElems)
    side_down.x_front(backElems)

    allSideElems.foreach(elem => elem.x_front(colorSequence))
    allAngleElems.foreach(elem => elem.x_front(colorSequence))
    allCenterElems.foreach(elem => elem.x_front(colorSequence))

    if (addStepSymbol) allSteps += "x"
  }
  def x_back(addStepSymbol: Boolean = true): Unit = {
    // front -> down
    changeColorSeq_xb()
    val upElems = side_up.getAllElems()
    val leftElems = side_left.getAllElems()
    val frontElems = side_front.getAllElems()
    val rightElems = side_right.getAllElems()
    val backElems = side_back.getAllElems()
    val downElems = side_down.getAllElems()

    side_up.x_back(backElems)
    side_left.x_back(leftElems)
    side_front.x_back(upElems)
    side_right.x_back(rightElems)
    side_back.x_back(downElems)
    side_down.x_back(frontElems)

    allSideElems.foreach(elem => elem.x_back(colorSequence))
    allAngleElems.foreach(elem => elem.x_back(colorSequence))
    allCenterElems.foreach(elem => elem.x_back(colorSequence))

    if (addStepSymbol) allSteps += "x'"
  }
  def y_front(addStepSymbol: Boolean = true): Unit = {
    // front -> left
    changeColorSeq_y()
    val upElems = side_up.getAllElems()
    val leftElems = side_left.getAllElems()
    val frontElems = side_front.getAllElems()
    val rightElems = side_right.getAllElems()
    val backElems = side_back.getAllElems()
    val downElems = side_down.getAllElems()

//    show_rubic_element_states()
//    println()

//    show_rubic_elements()
//    side_front.allElems.foreach(elem => print(s"${elem.getName}, "))
//    println()
    side_up.y_front(upElems)
    side_left.y_front(frontElems)
    side_front.y_front(rightElems)
    side_right.y_front(backElems)
    side_back.y_front(leftElems)
    side_down.y_front(downElems)
//    println()
//    show_rubic_elements()
//    println()

//    show_rubic_element_states()
//    println()
    allSideElems.foreach(elem => elem.y_front(colorSequence))
    allAngleElems.foreach(elem => elem.y_front(colorSequence))
    allCenterElems.foreach(elem => elem.y_front(colorSequence))

//    show_rubic_element_states()
//    println()

    if (addStepSymbol) allSteps += "y"
  }
  def y_back(addStepSymbol: Boolean = true): Unit = {
    // front -> right
    changeColorSeq_yb()
    val upElems = side_up.getAllElems()
    val leftElems = side_left.getAllElems()
    val frontElems = side_front.getAllElems()
    val rightElems = side_right.getAllElems()
    val backElems = side_back.getAllElems()
    val downElems = side_down.getAllElems()

    side_up.y_back(upElems)
    side_left.y_back(backElems)
    side_front.y_back(leftElems)
    side_right.y_back(frontElems)
    side_back.y_back(rightElems)
    side_down.y_back(downElems)

    allSideElems.foreach(elem => elem.y_back(colorSequence))
    allAngleElems.foreach(elem => elem.y_back(colorSequence))
    allCenterElems.foreach(elem => elem.y_back(colorSequence))

    if (addStepSymbol) allSteps += "y'"
  }
  def z_front(addStepSymbol: Boolean = true): Unit = {
    // up -> right
    changeColorSeq_z()
    val upElems = side_up.getAllElems()
    val leftElems = side_left.getAllElems()
    val frontElems = side_front.getAllElems()
    val rightElems = side_right.getAllElems()
    val backElems = side_back.getAllElems()
    val downElems = side_down.getAllElems()

    side_up.z_front(leftElems)
    side_left.z_front(downElems)
    side_front.z_front(frontElems)
    side_right.z_front(upElems)
    side_back.z_front(backElems)
    side_down.z_front(rightElems)

    allSideElems.foreach(elem => elem.z_front(colorSequence))
    allAngleElems.foreach(elem => elem.z_front(colorSequence))
    allCenterElems.foreach(elem => elem.z_front(colorSequence))

    if (addStepSymbol) allSteps += "z"
  }
  def z_back(addStepSymbol: Boolean = true): Unit = {
    // up -> left
    changeColorSeq_zb()
    val leftElems = side_left.getAllElems()
    val frontElems = side_front.getAllElems()
    val backElems = side_back.getAllElems()
    val downElems = side_down.getAllElems()
    val rightElems = side_right.getAllElems()
    val upElems = side_up.getAllElems()

//    show_rubic_element_states()
//    show_rubic_elements()

//    side_right.allElems.foreach(elem => print(s"${elem.getName} "))
    side_up.z_back(rightElems)
    side_left.z_back(upElems)
    side_front.z_back(frontElems)
    side_right.z_back(downElems)
    side_back.z_back(backElems)
    side_down.z_back(leftElems)

//    println()
//    //    show_rubic_element_states()
//    show_rubic_elements()

    allSideElems.foreach(elem => elem.z_back(colorSequence))
//    println()
//    show_rubic_element_states()
//    println()
    allAngleElems.foreach(elem => elem.z_back(colorSequence))
    allCenterElems.foreach(elem => elem.z_back(colorSequence))
//    show_rubic_element_states()

    if (addStepSymbol) allSteps += "z'"
//    show_rubic_elements()
  }
  def F_front(addStepSymbol: Boolean = true): Unit = {
    side_front.F_front()
    side_up.F_front(side_front.getUpElems)
    side_left.F_front(side_front.getLeftElems)
    side_down.F_front(side_front.getDownElems)
    side_right.F_front(side_front.getRightElems)

    if (addStepSymbol) allSteps += "F"
  }
  def F_back(addStepSymbol: Boolean = true): Unit = {
    side_front.F_back()
    side_up.F_back(side_front.getUpElems)
    side_left.F_back(side_front.getLeftElems)
    side_down.F_back(side_front.getDownElems)
    side_right.F_back(side_front.getRightElems)

    if (addStepSymbol) allSteps += "F'"
  }
  def F_front_double(addStepSymbol: Boolean = true): Unit = {
    side_front.F_front_double()
    side_up.F_front_double(side_front.getUpElems)
    side_left.F_front_double(side_front.getLeftElems)
    side_down.F_front_double(side_front.getDownElems)
    side_right.F_front_double(side_front.getRightElems)

    if (addStepSymbol) allSteps += "F2"
  }
  def F_back_double(addStepSymbol: Boolean = true): Unit = {
    side_front.F_back_double()
    side_up.F_back_double(side_front.getUpElems)
    side_left.F_back_double(side_front.getLeftElems)
    side_down.F_back_double(side_front.getDownElems)
    side_right.F_back_double(side_front.getRightElems)

    if (addStepSymbol) allSteps += "F2'"
  }
  def U_front(addStepSymbol: Boolean = true): Unit = {
    side_up.U_front()
    side_left.U_front(side_up.getLeftElems)
    side_front.U_front(side_up.getDownElems)
    side_right.U_front(side_up.getRightElems)
    side_back.U_front(side_up.getUpElems)

    if (addStepSymbol) allSteps += "U"
  }
  def U_back(addStepSymbol: Boolean = true): Unit  = {
    side_up.U_back()
    side_left.U_back(side_up.getLeftElems)
    side_front.U_back(side_up.getDownElems)
    side_right.U_back(side_up.getRightElems)
    side_back.U_back(side_up.getUpElems)

    if (addStepSymbol) allSteps += "U'"
  }
  def U_front_double(addStepSymbol: Boolean = true): Unit  = {
    side_up.U_front_double()
    side_left.U_front_double(side_up.getLeftElems)
    side_front.U_front_double(side_up.getDownElems)
    side_right.U_front_double(side_up.getRightElems)
    side_back.U_front_double(side_up.getUpElems)

    if (addStepSymbol) allSteps += "U2"
  }
  def U_back_double(addStepSymbol: Boolean = true): Unit  = {
    side_up.U_back_double()
    side_left.U_back_double(side_up.getLeftElems)
    side_front.U_back_double(side_up.getDownElems)
    side_right.U_back_double(side_up.getRightElems)
    side_back.U_back_double(side_up.getUpElems)

    if (addStepSymbol) allSteps += "U2'"
  }
  def D_front(addStepSymbol: Boolean = true): Unit = {
    side_down.D_front()
    side_left.D_front(side_down.getLeftElems)
    side_front.D_front(side_down.getUpElems)
    side_right.D_front(side_down.getRightElems)
    side_back.D_front(side_down.getDownElems)

    if (addStepSymbol) allSteps += "D"
  }
  def D_back(addStepSymbol: Boolean = true): Unit  = {
    side_down.D_back()
    side_left.D_back(side_down.getLeftElems)
    side_front.D_back(side_down.getUpElems)
    side_right.D_back(side_down.getRightElems)
    side_back.D_back(side_down.getDownElems)

    if (addStepSymbol) allSteps += "D'"
  }
  def D_front_double(addStepSymbol: Boolean = true): Unit  = {
    side_down.D_front_double()
    side_left.D_front_double(side_down.getLeftElems)
    side_front.D_front_double(side_down.getUpElems)
    side_right.D_front_double(side_down.getRightElems)
    side_back.D_front_double(side_down.getDownElems)

    if (addStepSymbol) allSteps += "D2"
  }
  def D_back_double(addStepSymbol: Boolean = true): Unit  = {
    side_down.D_back_double()
    side_left.D_back_double(side_down.getLeftElems)
    side_front.D_back_double(side_down.getUpElems)
    side_right.D_back_double(side_down.getRightElems)
    side_back.D_back_double(side_down.getDownElems)

    if (addStepSymbol) allSteps += "D2'"
  }
  def R_front(addStepSymbol: Boolean = true): Unit = {
    side_right.R_front()
    side_up.R_front(side_right.getUpElems)
    side_front.R_front(side_right.getLeftElems)
    side_down.R_front(side_right.getDownElems)
    side_back.R_front(side_right.getRightElems)

    if (addStepSymbol) allSteps += "R"
  }
  def R_back(addStepSymbol: Boolean = true): Unit  = {
    side_right.R_back()
    side_up.R_back(side_right.getUpElems)
    side_front.R_back(side_right.getLeftElems)
    side_down.R_back(side_right.getDownElems)
    side_back.R_back(side_right.getRightElems)

    if (addStepSymbol) allSteps += "R'"
  }
  def R_front_double(addStepSymbol: Boolean = true): Unit  = {
    side_right.R_front_double()
    side_up.R_front_double(side_right.getUpElems)
    side_front.R_front_double(side_right.getLeftElems)
    side_down.R_front_double(side_right.getDownElems)
    side_back.R_front_double(side_right.getRightElems)

    if (addStepSymbol) allSteps += "R2"
  }
  def R_back_double(addStepSymbol: Boolean = true): Unit  = {
    side_right.R_back_double()
    side_up.R_back_double(side_right.getUpElems)
    side_front.R_back_double(side_right.getLeftElems)
    side_down.R_back_double(side_right.getDownElems)
    side_back.R_back_double(side_right.getRightElems)

    if (addStepSymbol) allSteps += "R2'"
  }
  def L_front(addStepSymbol: Boolean = true): Unit = {
    side_left.L_front()
    side_up.L_front(side_left.getUpElems)
    side_front.L_front(side_left.getRightElems)
    side_down.L_front(side_left.getDownElems)
    side_back.L_front(side_left.getLeftElems)

    if (addStepSymbol) allSteps += "L"
  }
  def L_back(addStepSymbol: Boolean = true): Unit  = {
    side_left.L_back()
    side_up.L_back(side_left.getUpElems)
    side_front.L_back(side_left.getRightElems)
    side_down.L_back(side_left.getDownElems)
    side_back.L_back(side_left.getLeftElems)

    if (addStepSymbol) allSteps += "L'"
  }
  def L_front_double(addStepSymbol: Boolean = true): Unit  = {
    side_left.L_front_double()
    side_up.L_front_double(side_left.getUpElems)
    side_front.L_front_double(side_left.getRightElems)
    side_down.L_front_double(side_left.getDownElems)
    side_back.L_front_double(side_left.getLeftElems)

    if (addStepSymbol) allSteps += "L2"
  }
  def L_back_double(addStepSymbol: Boolean = true): Unit  = {
    side_left.L_back_double()
    side_up.L_back_double(side_left.getUpElems)
    side_front.L_back_double(side_left.getRightElems)
    side_down.L_back_double(side_left.getDownElems)
    side_back.L_back_double(side_left.getLeftElems)

    if (addStepSymbol) allSteps += "L2'"
  }
  def B_front(addStepSymbol: Boolean = true): Unit = {
    side_back.B_front()
    side_up.B_front(side_back.getUpElems)
    side_right.B_front(side_back.getLeftElems)
    side_down.B_front(side_back.getDownElems)
    side_left.B_front(side_back.getRightElems)

    if (addStepSymbol) allSteps += "B"
  }
  def B_back(addStepSymbol: Boolean = true): Unit  = {
    side_back.B_back()
    side_up.B_back(side_back.getUpElems)
    side_right.B_back(side_back.getLeftElems)
    side_down.B_back(side_back.getDownElems)
    side_left.B_back(side_back.getRightElems)

    if (addStepSymbol) allSteps += "B'"
  }
  def B_front_double(addStepSymbol: Boolean = true): Unit  = {
    side_back.B_front_double()
    side_up.B_front_double(side_back.getUpElems)
    side_right.B_front_double(side_back.getLeftElems)
    side_down.B_front_double(side_back.getDownElems)
    side_left.B_front_double(side_back.getRightElems)

    if (addStepSymbol) allSteps += "B2"
  }
  def B_back_double(addStepSymbol: Boolean = true): Unit  = {
    side_back.B_back_double()
    side_up.B_back_double(side_back.getUpElems)
    side_right.B_back_double(side_back.getLeftElems)
    side_down.B_back_double(side_back.getDownElems)
    side_left.B_back_double(side_back.getRightElems)

    if (addStepSymbol) allSteps += "B2'"
  }
}

object Rubic_new extends Collection_side_movies_crest_first
  with Collection_angle_movies_full_side_first
  with Collection_side_movies_second_layer
  with Collection_side_movies_for_prepare_F2L
  with Collection_angle_movies_for_prepare_F2L
  with Collection_movies_for_F2L
  with Collection_opposite_cross_after_F2L
  with Collection_COLL
  with Collection_PLL
