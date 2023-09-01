/*
    Side of rubic

    state_crest - state of crest in side Tuple2(<first>, <second>)
    first:
      c_zero:   All elems in their place
      c_one:    1 elem is out of place
      c_two:    2 elems is out of place
      c_three:  3 elems is out of place
      c_four:   Only center elem in their place
    second:
      p_zero: All elems in their place
      p_one_*:  F movie do stand side to their place
      p_two_*:  F2 movie do stand side to their place

    state_full - state all elems in side Tuple(<first>, <second>)
    first:
      c_zero:   All elems in their place
      c_one:    1 elem is out of place
      c_two:    2 elems is out of place
      c_three:  3 elems is out of place
      c_four:   4 elems is out of place
      c_five:   5 elems is out of place
      c_six:    6 elems is out of place
      c_seven:  7 elems is out of place
      c_eight:  Only center elem in their place
    second:
      p_zero: All elems in their place
      p_one_*:  F movie do stand side to their place
      p_two_*:  F2 movie do stand side to their place
 */

package src

import src.Angle_elem_position.Angle_elem_position
import src.Center_elem_position.Center_elem_position
import src.OppositeState.OppositeState
import src.Side.{backElemNamesTable_0, backElemNamesTable_1, backElemNamesTable_2, backElemNamesTable_3, collectionOppositeSideFullCompleteState, downElemNamesTable_0, downElemNamesTable_1, downElemNamesTable_2, downElemNamesTable_3, frontElemNamesTable_0, frontElemNamesTable_1, frontElemNamesTable_2, frontElemNamesTable_3, leftElemNamesTable_0, leftElemNamesTable_1, leftElemNamesTable_2, leftElemNamesTable_3, rightElemNamesTable_0, rightElemNamesTable_1, rightElemNamesTable_2, rightElemNamesTable_3, upElemNamesTable_0, upElemNamesTable_1, upElemNamesTable_2, upElemNamesTable_3}
import src.Side_elem_position.Side_elem_position
import src.Side_position.Side_position
import src.Side_position_with_rubic.Side_position_with_rubic
import src.Side_composition.Side_composition

import scala.collection.mutable

class Side(position: Side_position,
           var elem_tl: Elem_angle, var elem_tc: Elem_side, var elem_tr: Elem_angle,
           var elem_cl: Elem_side, var elem_cc: Elem_center, var elem_cr: Elem_side,
           var elem_dl: Elem_angle, var elem_dc: Elem_side, var elem_dr: Elem_angle) {

  private var state_crest = (Side_composition.c_zero, Side_position_with_rubic.p_zero)
  private var state_full = (Side_composition.c_zero, Side_position_with_rubic.p_zero)
  private val indicesSideElems = Array(1, 3, 5, 7)
  private val sideElemStateFinal = mutable.HashMap[Elem_side, Boolean](
    elem_tc -> true,
    elem_cl -> true,
    elem_cr -> true,
    elem_dc -> true
  )
  private val angleElemStateFinal = mutable.HashMap[Elem_angle, Boolean](
    elem_tl -> true,
    elem_tr -> true,
    elem_dl -> true,
    elem_dr -> true
  )
  def allSideElems: Array[Elem_side] = Array(elem_tc, elem_cl, elem_cr, elem_dc)
  def allAngleElems: Array[Elem_angle] = Array(elem_tl, elem_tr, elem_dl, elem_dr)
  def allElems: Array[Elem] = Array(elem_tl, elem_tc, elem_tr, elem_cl, elem_cc, elem_cr, elem_dl, elem_dc, elem_dr)
  def allElems2: (Elem_angle, Elem_side, Elem_angle, Elem_side, Elem_center, Elem_side, Elem_angle, Elem_side, Elem_angle) =
    (elem_tl, elem_tc, elem_tr, elem_cl, elem_cc, elem_cr, elem_dl, elem_dc, elem_dr)

  private def getFirstStateCrest(value: IndexedSeq[Any]): Side_composition = {
    value.size match {
      case 0 => Side_composition.c_four
      case 1 => Side_composition.c_three
      case 2 => Side_composition.c_two
      case 3 => Side_composition.c_one
      case 4 => Side_composition.c_zero
    }
  }
  private def getFirstStateFull(value: IndexedSeq[Any]): Side_composition = {
    value.size match {
      case 0 => {
//        println(s"getFirstStateFull in Side $position exception")
        Side_composition.c_zero
      }
      case 1 => Side_composition.c_eight
      case 2 => Side_composition.c_seven
      case 3 => Side_composition.c_six
      case 4 => Side_composition.c_five
      case 5 => Side_composition.c_four
      case 6 => Side_composition.c_three
      case 7 => Side_composition.c_two
      case 8 => Side_composition.c_one
      case 9 => Side_composition.c_zero
    }
  }
  private def max(ar: Array[IndexedSeq[Any]]): Int = {
    val p = for (elem <- ar) yield elem.size
    val k = p.max
    p.indexOf(k)
  }
  private def update_state_crest(): Unit = {
    val tmp_names = getNameElems
    elem_cc.color_1 match {
      case Elem_colors.white => {
        val var_0 = (for (i <- indicesSideElems) yield if (tmp_names(i) == upElemNamesTable_0(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_1 = (for (i <- indicesSideElems) yield if (tmp_names(i) == upElemNamesTable_1(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_2 = (for (i <- indicesSideElems) yield if (tmp_names(i) == upElemNamesTable_2(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_3 = (for (i <- indicesSideElems) yield if (tmp_names(i) == upElemNamesTable_3(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1, var_2, var_3))
//        println(s"1: ${var_0.mkString(", ")}; 2: ${var_1.mkString(", ")}; 3: ${var_2.mkString(", ")}; 4: ${var_3.mkString(", ")}")
//        println(s"white: ${max(Array(var_0, var_1, var_2, var_3))}")
        finest match {
          case 0 => state_crest = (getFirstStateCrest(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_crest = (getFirstStateCrest(var_1), Side_position_with_rubic.p_one_u)
          case 2 => state_crest = (getFirstStateCrest(var_2), Side_position_with_rubic.p_two_u)
          case 3 => state_crest = (getFirstStateCrest(var_3), Side_position_with_rubic.p_one_ub)
        }
      }
      case Elem_colors.orange => {
        val var_0 = (for (i <- indicesSideElems) yield if (tmp_names(i) == leftElemNamesTable_0(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_1 = (for (i <- indicesSideElems) yield if (tmp_names(i) == leftElemNamesTable_1(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_2 = (for (i <- indicesSideElems) yield if (tmp_names(i) == leftElemNamesTable_2(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_3 = (for (i <- indicesSideElems) yield if (tmp_names(i) == leftElemNamesTable_3(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_crest = (getFirstStateCrest(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_crest = (getFirstStateCrest(var_1), Side_position_with_rubic.p_one_l)
          case 2 => state_crest = (getFirstStateCrest(var_2), Side_position_with_rubic.p_two_l)
          case 3 => state_crest = (getFirstStateCrest(var_3), Side_position_with_rubic.p_one_lb)
        }
      }
      case Elem_colors.green => {
        val var_0 = (for (i <- indicesSideElems) yield if (tmp_names(i) == frontElemNamesTable_0(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_1 = (for (i <- indicesSideElems) yield if (tmp_names(i) == frontElemNamesTable_1(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_2 = (for (i <- indicesSideElems) yield if (tmp_names(i) == frontElemNamesTable_2(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_3 = (for (i <- indicesSideElems) yield if (tmp_names(i) == frontElemNamesTable_3(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_crest = (getFirstStateCrest(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_crest = (getFirstStateCrest(var_1), Side_position_with_rubic.p_one_f)
          case 2 => state_crest = (getFirstStateCrest(var_2), Side_position_with_rubic.p_two_f)
          case 3 => state_crest = (getFirstStateCrest(var_3), Side_position_with_rubic.p_one_fb)
        }
      }
      case Elem_colors.red => {
        val var_0 = (for (i <- indicesSideElems) yield if (tmp_names(i) == rightElemNamesTable_0(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_1 = (for (i <- indicesSideElems) yield if (tmp_names(i) == rightElemNamesTable_1(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_2 = (for (i <- indicesSideElems) yield if (tmp_names(i) == rightElemNamesTable_2(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_3 = (for (i <- indicesSideElems) yield if (tmp_names(i) == rightElemNamesTable_3(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_crest = (getFirstStateCrest(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_crest = (getFirstStateCrest(var_1), Side_position_with_rubic.p_one_r)
          case 2 => state_crest = (getFirstStateCrest(var_2), Side_position_with_rubic.p_two_r)
          case 3 => state_crest = (getFirstStateCrest(var_3), Side_position_with_rubic.p_one_rb)
        }
      }
      case Elem_colors.blue => {
        val var_0 = (for (i <- indicesSideElems) yield if (tmp_names(i) == backElemNamesTable_0(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_1 = (for (i <- indicesSideElems) yield if (tmp_names(i) == backElemNamesTable_1(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_2 = (for (i <- indicesSideElems) yield if (tmp_names(i) == backElemNamesTable_2(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_3 = (for (i <- indicesSideElems) yield if (tmp_names(i) == backElemNamesTable_3(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_crest = (getFirstStateCrest(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_crest = (getFirstStateCrest(var_1), Side_position_with_rubic.p_one_b)
          case 2 => state_crest = (getFirstStateCrest(var_2), Side_position_with_rubic.p_two_b)
          case 3 => state_crest = (getFirstStateCrest(var_3), Side_position_with_rubic.p_one_bb)
        }
      }
      case Elem_colors.yellow => {
        val var_0 = (for (i <- indicesSideElems) yield if (tmp_names(i) == downElemNamesTable_0(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_1 = (for (i <- indicesSideElems) yield if (tmp_names(i) == downElemNamesTable_1(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_2 = (for (i <- indicesSideElems) yield if (tmp_names(i) == downElemNamesTable_2(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val var_3 = (for (i <- indicesSideElems) yield if (tmp_names(i) == downElemNamesTable_3(i)) tmp_names(i) else "").filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_crest = (getFirstStateCrest(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_crest = (getFirstStateCrest(var_1), Side_position_with_rubic.p_one_d)
          case 2 => state_crest = (getFirstStateCrest(var_2), Side_position_with_rubic.p_two_d)
          case 3 => state_crest = (getFirstStateCrest(var_3), Side_position_with_rubic.p_one_db)
        }
      }
    }
//    println(s"update state crest finish ${elem_cc.color_1}: ${state_crest._1.toString}, ${state_crest._2.toString}")
  }
  private def update_state_full(): Unit = {
    val tmp_names = getNameElems
//    println(s"side - ${position.toString}, names: ${tmp_names.mkString(",")}")
    position match {
      case Side_position.up => {
        val var_0 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == upElemNamesTable_0(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_1 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == upElemNamesTable_1(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_2 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == upElemNamesTable_2(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_3 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == upElemNamesTable_3(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_full = (getFirstStateFull(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_full = (getFirstStateFull(var_1), Side_position_with_rubic.p_one_u)
          case 2 => state_full = (getFirstStateFull(var_2), Side_position_with_rubic.p_two_u)
          case 3 => state_full = (getFirstStateFull(var_3), Side_position_with_rubic.p_one_ub)
        }
      }
      case Side_position.left => {
        val var_0 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == leftElemNamesTable_0(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_1 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == leftElemNamesTable_1(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_2 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == leftElemNamesTable_2(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_3 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == leftElemNamesTable_3(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_full = (getFirstStateFull(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_full = (getFirstStateFull(var_1), Side_position_with_rubic.p_one_l)
          case 2 => state_full = (getFirstStateFull(var_2), Side_position_with_rubic.p_two_l)
          case 3 => state_full = (getFirstStateFull(var_3), Side_position_with_rubic.p_one_lb)
        }
      }
      case Side_position.front => {
        val var_0 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == frontElemNamesTable_0(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_1 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == frontElemNamesTable_1(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_2 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == frontElemNamesTable_2(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_3 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == frontElemNamesTable_3(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_full = (getFirstStateFull(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_full = (getFirstStateFull(var_1), Side_position_with_rubic.p_one_f)
          case 2 => state_full = (getFirstStateFull(var_2), Side_position_with_rubic.p_two_f)
          case 3 => state_full = (getFirstStateFull(var_3), Side_position_with_rubic.p_one_fb)
        }
      }
      case Side_position.right => {
        val var_0 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == rightElemNamesTable_0(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_1 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == rightElemNamesTable_1(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_2 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == rightElemNamesTable_2(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_3 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == rightElemNamesTable_3(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_full = (getFirstStateFull(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_full = (getFirstStateFull(var_1), Side_position_with_rubic.p_one_r)
          case 2 => state_full = (getFirstStateFull(var_2), Side_position_with_rubic.p_two_r)
          case 3 => state_full = (getFirstStateFull(var_3), Side_position_with_rubic.p_one_rb)
        }
      }
      case Side_position.back => {
        val var_0 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == backElemNamesTable_0(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_1 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == backElemNamesTable_1(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_2 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == backElemNamesTable_2(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_3 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == backElemNamesTable_3(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_full = (getFirstStateFull(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_full = (getFirstStateFull(var_1), Side_position_with_rubic.p_one_b)
          case 2 => state_full = (getFirstStateFull(var_2), Side_position_with_rubic.p_two_b)
          case 3 => state_full = (getFirstStateFull(var_3), Side_position_with_rubic.p_one_bb)
        }
      }
      case Side_position.down => {
        val var_0 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == downElemNamesTable_0(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_1 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == downElemNamesTable_1(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_2 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == downElemNamesTable_2(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val var_3 = (for (i <- tmp_names.indices) yield if (tmp_names(i) == downElemNamesTable_3(i)) tmp_names(i) else "").toArray.filter(str => str.nonEmpty)
        val finest = max(Array(var_0, var_1,  var_2, var_3))
        finest match {
          case 0 => state_full = (getFirstStateFull(var_0), Side_position_with_rubic.p_zero)
          case 1 => state_full = (getFirstStateFull(var_1), Side_position_with_rubic.p_one_d)
          case 2 => state_full = (getFirstStateFull(var_2), Side_position_with_rubic.p_two_d)
          case 3 => state_full = (getFirstStateFull(var_3), Side_position_with_rubic.p_one_db)
        }
      }
    }
  }

  def mkString(): String = {
    elem_tl.get_color(position).toString + elem_tc.get_color(position).toString + elem_tr.get_color(position).toString +
      elem_cl.get_color(position).toString + elem_cc.get_color().toString + elem_cr.get_color(position).toString +
      elem_dl.get_color(position).toString + elem_dc.get_color(position).toString + elem_dr.get_color(position).toString
  }
  def getNameElems: Array[String] = {
    Array(
      elem_tl.getName, elem_tc.getName, elem_tr.getName,
      elem_cl.getName, elem_cc.getName, elem_cr.getName,
      elem_dl.getName, elem_dc.getName, elem_dr.getName
    )
  }
  def getElemState: Tuple9[Angle_elem_position,
    Side_elem_position,  Angle_elem_position,
    Side_elem_position, Center_elem_position,
    Side_elem_position,  Angle_elem_position,
    Side_elem_position,  Angle_elem_position] = {
    (elem_tl.getElemState, elem_tc.getElemState, elem_tr.getElemState,
      elem_cl.getElemState, elem_cc.getCurrentPos, elem_cr.getElemState,
      elem_dl.getElemState, elem_dc.getElemState, elem_dr.getElemState)
  }
  def x_front(elems: (Elem_angle, Elem_side, Elem_angle,
                      Elem_side, Elem_center, Elem_side,
                      Elem_angle, Elem_side, Elem_angle)): Unit = {
    // front -> up
    position match {
      case Side_position.left =>
        elem_tl = elems._3
        elem_tc = elems._6
        elem_tr = elems._9
        elem_cl = elems._2
        elem_cc = elems._5
        elem_cr = elems._8
        elem_dl = elems._1
        elem_dc = elems._4
        elem_dr = elems._7
      case Side_position.right =>
        elem_tl = elems._7
        elem_tc = elems._4
        elem_tr = elems._1
        elem_cl = elems._8
        elem_cc = elems._5
        elem_cr = elems._2
        elem_dl = elems._9
        elem_dc = elems._6
        elem_dr = elems._3
      case Side_position.back | Side_position.down =>
        elem_tl = elems._9
        elem_tc = elems._8
        elem_tr = elems._7
        elem_cl = elems._6
        elem_cc = elems._5
        elem_cr = elems._4
        elem_dl = elems._3
        elem_dc = elems._2
        elem_dr = elems._1
      case _ =>
        elem_tl = elems._1
        elem_tc = elems._2
        elem_tr = elems._3
        elem_cl = elems._4
        elem_cc = elems._5
        elem_cr = elems._6
        elem_dl = elems._7
        elem_dc = elems._8
        elem_dr = elems._9
    }
    update_state_crest()
    update_state_full()
  }
  def x_back(elems: (Elem_angle, Elem_side, Elem_angle,
                      Elem_side, Elem_center, Elem_side,
                      Elem_angle, Elem_side, Elem_angle)): Unit = {
    // front -> down
    position match {
      case Side_position.up | Side_position.back =>
        elem_tl = elems._9
        elem_tc = elems._8
        elem_tr = elems._7
        elem_cl = elems._6
        elem_cc = elems._5
        elem_cr = elems._4
        elem_dl = elems._3
        elem_dc = elems._2
        elem_dr = elems._1
      case Side_position.left =>
        elem_tl = elems._7
        elem_tc = elems._4
        elem_tr = elems._1
        elem_cl = elems._8
        elem_cc = elems._5
        elem_cr = elems._2
        elem_dl = elems._9
        elem_dc = elems._6
        elem_dr = elems._3
      case Side_position.right =>
        elem_tl = elems._3
        elem_tc = elems._6
        elem_tr = elems._9
        elem_cl = elems._2
        elem_cc = elems._5
        elem_cr = elems._8
        elem_dl = elems._1
        elem_dc = elems._4
        elem_dr = elems._7
      case _ =>
        elem_tl = elems._1
        elem_tc = elems._2
        elem_tr = elems._3
        elem_cl = elems._4
        elem_cc = elems._5
        elem_cr = elems._6
        elem_dl = elems._7
        elem_dc = elems._8
        elem_dr = elems._9
    }
    update_state_crest()
    update_state_full()
  }
  def y_front(elems: (Elem_angle, Elem_side, Elem_angle,
                      Elem_side, Elem_center, Elem_side,
                      Elem_angle, Elem_side, Elem_angle)): Unit = {
    // front -> left
    position match {
      case Side_position.up =>
        elem_tl = elems._7
        elem_tc = elems._4
        elem_tr = elems._1
        elem_cl = elems._8
        elem_cc = elems._5
        elem_cr = elems._2
        elem_dl = elems._9
        elem_dc = elems._6
        elem_dr = elems._3
      case Side_position.down =>
        elem_tl = elems._3
        elem_tc = elems._6
        elem_tr = elems._9
        elem_cl = elems._2
        elem_cc = elems._5
        elem_cr = elems._8
        elem_dl = elems._1
        elem_dc = elems._4
        elem_dr = elems._7
      case _ =>
        elem_tl = elems._1
        elem_tc = elems._2
        elem_tr = elems._3
        elem_cl = elems._4
        elem_cc = elems._5
        elem_cr = elems._6
        elem_dl = elems._7
        elem_dc = elems._8
        elem_dr = elems._9
    }
    update_state_crest()
    update_state_full()
  }
  def y_back(elems: (Elem_angle, Elem_side, Elem_angle,
                      Elem_side, Elem_center, Elem_side,
                      Elem_angle, Elem_side, Elem_angle)): Unit = {
    // front -> right
    position match {
      case Side_position.up =>
        elem_tl = elems._3
        elem_tc = elems._6
        elem_tr = elems._9
        elem_cl = elems._2
        elem_cc = elems._5
        elem_cr = elems._8
        elem_dl = elems._1
        elem_dc = elems._4
        elem_dr = elems._7
      case Side_position.down =>
        elem_tl = elems._7
        elem_tc = elems._4
        elem_tr = elems._1
        elem_cl = elems._8
        elem_cc = elems._5
        elem_cr = elems._2
        elem_dl = elems._9
        elem_dc = elems._6
        elem_dr = elems._3
      case _ =>
        elem_tl = elems._1
        elem_tc = elems._2
        elem_tr = elems._3
        elem_cl = elems._4
        elem_cc = elems._5
        elem_cr = elems._6
        elem_dl = elems._7
        elem_dc = elems._8
        elem_dr = elems._9
    }
    update_state_crest()
    update_state_full()
  }
  def z_front(elems: (Elem_angle, Elem_side, Elem_angle,
                      Elem_side, Elem_center, Elem_side,
                      Elem_angle, Elem_side, Elem_angle)): Unit = {
      // up -> right
      position match {
        case Side_position.back =>
          elem_tl = elems._3
          elem_tc = elems._6
          elem_tr = elems._9
          elem_cl = elems._2
          elem_cc = elems._5
          elem_cr = elems._8
          elem_dl = elems._1
          elem_dc = elems._4
          elem_dr = elems._7
        case _ =>
          elem_tl = elems._7
          elem_tc = elems._4
          elem_tr = elems._1
          elem_cl = elems._8
          elem_cc = elems._5
          elem_cr = elems._2
          elem_dl = elems._9
          elem_dc = elems._6
          elem_dr = elems._3
    }
    update_state_crest()
    update_state_full()
  }
  def z_back(elems: (Elem_angle, Elem_side, Elem_angle,
                      Elem_side, Elem_center, Elem_side,
                      Elem_angle, Elem_side, Elem_angle)): Unit = {
    // up -> left
      position match {
        case Side_position.back =>
          elem_tl = elems._7
          elem_tc = elems._4
          elem_tr = elems._1
          elem_cl = elems._8
          elem_cc = elems._5
          elem_cr = elems._2
          elem_dl = elems._9
          elem_dc = elems._6
          elem_dr = elems._3
        case _ =>
          elem_tl = elems._3
          elem_tc = elems._6
          elem_tr = elems._9
          elem_cl = elems._2
          elem_cc = elems._5
          elem_cr = elems._8
          elem_dl = elems._1
          elem_dc = elems._4
          elem_dr = elems._7
    }
    update_state_crest()
    update_state_full()
  }
  private def F_front_change(): Unit = {
    val tl_tmp = elem_tl
    val tc_tmp = elem_tc
    val tr_tmp = elem_tr
    val cl_tmp = elem_cl
    val cr_tmp = elem_cr
    val dl_tmp = elem_dl
    val dc_tmp = elem_dc
    val dr_tmp = elem_dr
    elem_tl = dl_tmp
    elem_tc = cl_tmp
    elem_tr = tl_tmp
    elem_cr = tc_tmp
    elem_dr = tr_tmp
    elem_dc = cr_tmp
    elem_dl = dr_tmp
    elem_cl = dc_tmp
  }
  def F_front(): Unit = {
    F_front_change()
    elem_tl.F_front()
    elem_tc.F_front()
    elem_tr.F_front()
    elem_cr.F_front()
    elem_dr.F_front()
    elem_dc.F_front()
    elem_dl.F_front()
    elem_cl.F_front()

    update_state_crest()
    update_state_full()
  }
  def F_front(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = {
    position match {
      case Side_position.up => {
        elem_dl = newElems._1
        elem_dc = newElems._2
        elem_dr = newElems._3
      }
      case Side_position.left => {
        elem_tr = newElems._1
        elem_cr = newElems._2
        elem_dr = newElems._3
      }
      case Side_position.down => {
        elem_tl = newElems._1
        elem_tc = newElems._2
        elem_tr = newElems._3
      }
      case Side_position.right => {
        elem_tl = newElems._1
        elem_cl = newElems._2
        elem_dl = newElems._3
      }
    }

    update_state_crest()
    update_state_full()
  }
  private def F_back_change(): Unit = {
    val tl_tmp = elem_tl
    val tc_tmp = elem_tc
    val tr_tmp = elem_tr
    val cl_tmp = elem_cl
    val cr_tmp = elem_cr
    val dl_tmp = elem_dl
    val dc_tmp = elem_dc
    val dr_tmp = elem_dr
    elem_tl = tr_tmp
    elem_tc = cr_tmp
    elem_tr = dr_tmp
    elem_cr = dc_tmp
    elem_dr = dl_tmp
    elem_dc = cl_tmp
    elem_dl = tl_tmp
    elem_cl = tc_tmp
  }
  def F_back(): Unit = {
    F_back_change()
    elem_tl.F_back()
    elem_tc.F_back()
    elem_tr.F_back()
    elem_cr.F_back()
    elem_dr.F_back()
    elem_dc.F_back()
    elem_dl.F_back()
    elem_cl.F_back()

    update_state_crest()
    update_state_full()
  }
  def F_back(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = F_front(newElems)
  private def F_front_double_change(): Unit = {
    val tl_tmp = elem_tl
    val tc_tmp = elem_tc
    val tr_tmp = elem_tr
    val cl_tmp = elem_cl
    val cr_tmp = elem_cr
    val dl_tmp = elem_dl
    val dc_tmp = elem_dc
    val dr_tmp = elem_dr
    elem_tl = dr_tmp
    elem_tc = dc_tmp
    elem_tr = dl_tmp
    elem_cr = cl_tmp
    elem_dr = tl_tmp
    elem_dc = tc_tmp
    elem_dl = tr_tmp
    elem_cl = cr_tmp
  }
  def F_front_double(): Unit = {
    F_front_double_change()
    elem_tl.F_front_double()
    elem_tc.F_front_double()
    elem_tr.F_front_double()
    elem_cr.F_front_double()
    elem_dr.F_front_double()
    elem_dc.F_front_double()
    elem_dl.F_front_double()
    elem_cl.F_front_double()

    update_state_crest()
    update_state_full()
  }
  def F_front_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = F_front(newElems)
  private def F_back_double_change(): Unit = {
    val tl_tmp = elem_tl
    val tc_tmp = elem_tc
    val tr_tmp = elem_tr
    val cl_tmp = elem_cl
    val cr_tmp = elem_cr
    val dl_tmp = elem_dl
    val dc_tmp = elem_dc
    val dr_tmp = elem_dr
    elem_tl = dr_tmp
    elem_tc = dc_tmp
    elem_tr = dl_tmp
    elem_cr = cl_tmp
    elem_dr = tl_tmp
    elem_dc = tc_tmp
    elem_dl = tr_tmp
    elem_cl = cr_tmp
  }
  def F_back_double(): Unit = {
    F_back_double_change()
    elem_tl.F_back_double()
    elem_tc.F_back_double()
    elem_tr.F_back_double()
    elem_cr.F_back_double()
    elem_dr.F_back_double()
    elem_dc.F_back_double()
    elem_dl.F_back_double()
    elem_cl.F_back_double()

    update_state_crest()
    update_state_full()
  }
  def F_back_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = F_front(newElems)
  def U_front(): Unit = {
    F_front_change()
    elem_tl.U_front()
    elem_tc.U_front()
    elem_tr.U_front()
    elem_cr.U_front()
    elem_dr.U_front()
    elem_dc.U_front()
    elem_dl.U_front()
    elem_cl.U_front()

    update_state_crest()
    update_state_full()
  }
  def U_front(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = {
    position match {
      case Side_position.back => {
        elem_tl = newElems._3
        elem_tc = newElems._2
        elem_tr = newElems._1
      }
      case Side_position.left => {
        elem_tl = newElems._1
        elem_tc = newElems._2
        elem_tr = newElems._3
      }
      case Side_position.front => {
        elem_tl = newElems._1
        elem_tc = newElems._2
        elem_tr = newElems._3
      }
      case Side_position.right => {
        elem_tl = newElems._3
        elem_tc = newElems._2
        elem_tr = newElems._1
      }
    }

    update_state_crest()
    update_state_full()
  }
  def U_back(): Unit = {
    F_back_change()
    elem_tl.U_back()
    elem_tc.U_back()
    elem_tr.U_back()
    elem_cr.U_back()
    elem_dr.U_back()
    elem_dc.U_back()
    elem_dl.U_back()
    elem_cl.U_back()

    update_state_crest()
    update_state_full()
  }
  def U_back(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = U_front(newElems)
  def U_front_double(): Unit = {
    F_front_double_change()
    elem_tl.U_front_double()
    elem_tc.U_front_double()
    elem_tr.U_front_double()
    elem_cr.U_front_double()
    elem_dr.U_front_double()
    elem_dc.U_front_double()
    elem_dl.U_front_double()
    elem_cl.U_front_double()

    update_state_crest()
    update_state_full()
  }
  def U_front_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = U_front(newElems)
  def U_back_double(): Unit = {
    F_back_double_change()
    elem_tl.U_back_double()
    elem_tc.U_back_double()
    elem_tr.U_back_double()
    elem_cr.U_back_double()
    elem_dr.U_back_double()
    elem_dc.U_back_double()
    elem_dl.U_back_double()
    elem_cl.U_back_double()

    update_state_crest()
    update_state_full()
  }
  def U_back_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = U_front(newElems)
  def D_front(): Unit = {
    F_front_change()
    elem_tl.D_front()
    elem_tc.D_front()
    elem_tr.D_front()
    elem_cr.D_front()
    elem_dr.D_front()
    elem_dc.D_front()
    elem_dl.D_front()
    elem_cl.D_front()

    update_state_crest()
    update_state_full()
  }
  def D_front(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = {
    position match {
      case Side_position.back => {
        elem_dl = newElems._3
        elem_dc = newElems._2
        elem_dr = newElems._1
      }
      case Side_position.left => {
        elem_dl = newElems._3
        elem_dc = newElems._2
        elem_dr = newElems._1
      }
      case Side_position.front => {
        elem_dl = newElems._1
        elem_dc = newElems._2
        elem_dr = newElems._3
      }
      case Side_position.right => {
        elem_dl = newElems._1
        elem_dc = newElems._2
        elem_dr = newElems._3
      }
    }

    update_state_crest()
    update_state_full()
  }
  def D_back(): Unit = {
    F_back_change()
    elem_tl.D_back()
    elem_tc.D_back()
    elem_tr.D_back()
    elem_cr.D_back()
    elem_dr.D_back()
    elem_dc.D_back()
    elem_dl.D_back()
    elem_cl.D_back()

    update_state_crest()
    update_state_full()
  }
  def D_back(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = D_front(newElems)
  def D_front_double(): Unit = {
    F_front_double_change()
    elem_tl.D_front_double()
    elem_tc.D_front_double()
    elem_tr.D_front_double()
    elem_cr.D_front_double()
    elem_dr.D_front_double()
    elem_dc.D_front_double()
    elem_dl.D_front_double()
    elem_cl.D_front_double()

    update_state_crest()
    update_state_full()
  }
  def D_front_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = D_front(newElems)
  def D_back_double(): Unit = {
    F_back_double_change()
    elem_tl.D_back_double()
    elem_tc.D_back_double()
    elem_tr.D_back_double()
    elem_cr.D_back_double()
    elem_dr.D_back_double()
    elem_dc.D_back_double()
    elem_dl.D_back_double()
    elem_cl.D_back_double()

    update_state_crest()
    update_state_full()
  }
  def D_back_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = D_front(newElems)
  def R_front(): Unit = {
    F_front_change()
    elem_tl.R_front()
    elem_tc.R_front()
    elem_tr.R_front()
    elem_cr.R_front()
    elem_dr.R_front()
    elem_dc.R_front()
    elem_dl.R_front()
    elem_cl.R_front()

    update_state_crest()
    update_state_full()
  }
  def R_front(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = {
    position match {
      case Side_position.up => {
        elem_tr = newElems._3
        elem_cr = newElems._2
        elem_dr = newElems._1
      }
      case Side_position.front => {
        elem_tr = newElems._1
        elem_cr = newElems._2
        elem_dr = newElems._3
      }
      case Side_position.down => {
        elem_tr = newElems._1
        elem_cr = newElems._2
        elem_dr = newElems._3
      }
      case Side_position.back => {
        elem_tl = newElems._1
        elem_cl = newElems._2
        elem_dl = newElems._3
      }
    }

    update_state_crest()
    update_state_full()
  }
  def R_back(): Unit = {
    F_back_change()
    elem_tl.R_back()
    elem_tc.R_back()
    elem_tr.R_back()
    elem_cr.R_back()
    elem_dr.R_back()
    elem_dc.R_back()
    elem_dl.R_back()
    elem_cl.R_back()

    update_state_crest()
    update_state_full()
  }
  def R_back(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = R_front(newElems)
  def R_front_double(): Unit = {
    F_front_double_change()
    elem_tl.R_front_double()
    elem_tc.R_front_double()
    elem_tr.R_front_double()
    elem_cr.R_front_double()
    elem_dr.R_front_double()
    elem_dc.R_front_double()
    elem_dl.R_front_double()
    elem_cl.R_front_double()

    update_state_crest()
    update_state_full()
  }
  def R_front_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = R_front(newElems)
  def R_back_double(): Unit = {
    F_back_double_change()
    elem_tl.R_back_double()
    elem_tc.R_back_double()
    elem_tr.R_back_double()
    elem_cr.R_back_double()
    elem_dr.R_back_double()
    elem_dc.R_back_double()
    elem_dl.R_back_double()
    elem_cl.R_back_double()

    update_state_crest()
    update_state_full()
  }
  def R_back_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = R_front(newElems)
  def L_front(): Unit = {
    F_front_change()
    elem_tl.L_front()
    elem_tc.L_front()
    elem_tr.L_front()
    elem_cr.L_front()
    elem_dr.L_front()
    elem_dc.L_front()
    elem_dl.L_front()
    elem_cl.L_front()

    update_state_crest()
    update_state_full()
  }
  def L_front(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = {
    position match {
      case Side_position.up => {
        elem_tl = newElems._1
        elem_cl = newElems._2
        elem_dl = newElems._3
      }
      case Side_position.front => {
        elem_tl = newElems._1
        elem_cl = newElems._2
        elem_dl = newElems._3
      }
      case Side_position.down => {
        elem_tl = newElems._3
        elem_cl = newElems._2
        elem_dl = newElems._1
      }
      case Side_position.back => {
        elem_tr = newElems._1
        elem_cr = newElems._2
        elem_dr = newElems._3
      }
    }

    update_state_crest()
    update_state_full()
  }
  def L_back(): Unit = {
    F_back_change()
    elem_tl.L_back()
    elem_tc.L_back()
    elem_tr.L_back()
    elem_cr.L_back()
    elem_dr.L_back()
    elem_dc.L_back()
    elem_dl.L_back()
    elem_cl.L_back()

    update_state_crest()
    update_state_full()
  }
  def L_back(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = L_front(newElems)
  def L_front_double(): Unit = {
    F_front_double_change()
    elem_tl.L_front_double()
    elem_tc.L_front_double()
    elem_tr.L_front_double()
    elem_cr.L_front_double()
    elem_dr.L_front_double()
    elem_dc.L_front_double()
    elem_dl.L_front_double()
    elem_cl.L_front_double()

    update_state_crest()
    update_state_full()
  }
  def L_front_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = L_front(newElems)
  def L_back_double(): Unit = {
    F_back_double_change()
    elem_tl.L_back_double()
    elem_tc.L_back_double()
    elem_tr.L_back_double()
    elem_cr.L_back_double()
    elem_dr.L_back_double()
    elem_dc.L_back_double()
    elem_dl.L_back_double()
    elem_cl.L_back_double()

    update_state_crest()
    update_state_full()
  }
  def L_back_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = L_front(newElems)
  def B_front(): Unit = {
    F_front_change()
    elem_tl.B_front()
    elem_tc.B_front()
    elem_tr.B_front()
    elem_cr.B_front()
    elem_dr.B_front()
    elem_dc.B_front()
    elem_dl.B_front()
    elem_cl.B_front()

    update_state_crest()
    update_state_full()
  }
  def B_front(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = {
    position match {
      case Side_position.left => {
        elem_tl = newElems._1
        elem_cl = newElems._2
        elem_dl = newElems._3
      }
      case Side_position.up => {
        elem_tl = newElems._3
        elem_tc = newElems._2
        elem_tr = newElems._1
      }
      case Side_position.right => {
        elem_tr = newElems._1
        elem_cr = newElems._2
        elem_dr = newElems._3
      }
      case Side_position.down => {
        elem_dl = newElems._3
        elem_dc = newElems._2
        elem_dr = newElems._1
      }
    }

    update_state_crest()
    update_state_full()
  }
  def B_back(): Unit = {
    F_back_change()
    elem_tl.B_back()
    elem_tc.B_back()
    elem_tr.B_back()
    elem_cr.B_back()
    elem_dr.B_back()
    elem_dc.B_back()
    elem_dl.B_back()
    elem_cl.B_back()

    update_state_crest()
    update_state_full()
  }
  def B_back(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = B_front(newElems)
  def B_front_double(): Unit = {
    F_front_double_change()
    elem_tl.B_front_double()
    elem_tc.B_front_double()
    elem_tr.B_front_double()
    elem_cr.B_front_double()
    elem_dr.B_front_double()
    elem_dc.B_front_double()
    elem_dl.B_front_double()
    elem_cl.B_front_double()

    update_state_crest()
    update_state_full()
  }
  def B_front_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = B_front(newElems)
  def B_back_double(): Unit = {
    F_back_double_change()
    elem_tl.B_back_double()
    elem_tc.B_back_double()
    elem_tr.B_back_double()
    elem_cr.B_back_double()
    elem_dr.B_back_double()
    elem_dc.B_back_double()
    elem_dl.B_back_double()
    elem_cl.B_back_double()

    update_state_crest()
    update_state_full()
  }
  def B_back_double(newElems: Tuple3[Elem_angle, Elem_side, Elem_angle]): Unit = B_front(newElems)

  def getUpElems: Tuple3[Elem_angle, Elem_side, Elem_angle] = (elem_tl, elem_tc, elem_tr)
  def getLeftElems: Tuple3[Elem_angle, Elem_side, Elem_angle] = (elem_tl, elem_cl, elem_dl)
  def getDownElems: Tuple3[Elem_angle, Elem_side, Elem_angle] = (elem_dl, elem_dc, elem_dr)
  def getRightElems: Tuple3[Elem_angle, Elem_side, Elem_angle] = (elem_tr, elem_cr, elem_dr)
  def getPosition: Side_position = position
  def getStateCrest: (src.Side_composition.Value, src.Side_position_with_rubic.Value) = state_crest
  def getStateFull: (src.Side_composition.Value, src.Side_position_with_rubic.Value) = state_full

  private def updateSideElemStateFinal(): Unit = {
    for (side <- sideElemStateFinal.keys) {
      if (side.getCurrentPos == side.getTargetPos)
        sideElemStateFinal(side) = true
      else
        sideElemStateFinal(side) = false
    }
  }
  private def updateAngleElemStateFinal(): Unit = {
    for (side <- angleElemStateFinal.keys) {
      println(s"next iteration: name:${side.getName}, target_state:${side.getTargetPos}, current_pos:${side.getCurrentPos}")
      if (side.getCurrentPos == side.getTargetPos)
        angleElemStateFinal(side) = true
      else
        angleElemStateFinal(side) = false
    }
  }

  def getNextReqSideElem: Elem_side = {
    updateSideElemStateFinal()
    val arr = sideElemStateFinal.filter(elem => !elem._2)
    arr.head._1
  }
  def getNextReqAngleElem: Elem_angle = {
    updateAngleElemStateFinal()
    val arr = angleElemStateFinal.filter(elem => !elem._2)
//    println(s"getNextReqAngleElem: array size ${arr.size}")
    arr.head._1
  }

  def checkCrest(): Boolean = if ((for (elem <- allSideElems) yield elem.checkComplete).contains(false)) false else true
  def checkCrestOnlyOneColor(forSide: Side_position): Boolean = {
//    if ((for (elem <- allSideElems) yield if (elem.color_1 == elem_cc.color_1) true else false).contains(false))
//      false
//    else
//      true
    if (allSideElems.exists(elem => elem.get_color(forSide) != elem_cc.get_color())) false else true
  }
  def checkFullOnlyOneColor(): Boolean = {
    if ((for (elem <- allElems) yield if (elem.color_1 == elem_cc.color_1) true else false).contains(false))
      false
    else
      true
  }
  def checkFullComplete(): Boolean = {
//    println(s"check up full complete start")
//    for (elem <- allElems) print(s"${elem.getName}: ${elem.getCurrentPos}|${elem.getTargetPos}  ")
//    println(s"\nresult check full ${allSideElems.exists(elem => elem.checkComplete == false)}; ${allAngleElems.exists(elem => elem.checkComplete == false)}")
    if (allSideElems.exists(elem => elem.checkComplete == false) ||
        allAngleElems.exists(elem => elem.checkComplete == false)) false else true
  }
  def checkSecondLayerComplete(side_position: Side_position): Boolean = {
    side_position match {
      case Side_position.up => if (elem_cl.checkComplete && elem_cc.checkComplete && elem_cr.checkComplete) true else false
      case Side_position.left => if (elem_tc.checkComplete && elem_cc.checkComplete && elem_dc.checkComplete) true else false
      case Side_position.front =>
        position match {
          case Side_position.up => if (elem_cl.checkComplete && elem_cc.checkComplete && elem_cr.checkComplete) true else false
          case Side_position.left => if (elem_tc.checkComplete && elem_cc.checkComplete && elem_dc.checkComplete) true else false
          case Side_position.front => false // Not used
          case Side_position.right => if (elem_tc.checkComplete && elem_cc.checkComplete && elem_dc.checkComplete) true else false
          case Side_position.back => false // Not used
          case Side_position.down => if (elem_cl.checkComplete && elem_cc.checkComplete && elem_cr.checkComplete) true else false
        }
      case Side_position.right => if (elem_tc.checkComplete && elem_cc.checkComplete && elem_dc.checkComplete) true else false
      case Side_position.back =>
        position match {
          case Side_position.up => if (elem_cl.checkComplete && elem_cc.checkComplete && elem_cr.checkComplete) true else false
          case Side_position.left => if (elem_tc.checkComplete && elem_cc.checkComplete && elem_dc.checkComplete) true else false
          case Side_position.front => false // Not used
          case Side_position.right => if (elem_tc.checkComplete && elem_cc.checkComplete && elem_dc.checkComplete) true else false
          case Side_position.back => false // Not used
          case Side_position.down => if (elem_cl.checkComplete && elem_cc.checkComplete && elem_cr.checkComplete) true else false
        }
      case Side_position.down => if (elem_cl.checkComplete && elem_cc.checkComplete && elem_cr.checkComplete) true else false
    }
  }
  def getNextRequiredSideElemForSecondLayer(side_position: Side_position): Elem_side = {
    side_position match {
      case Side_position.up => if (elem_cl.checkComplete) elem_cr else elem_cl
      case Side_position.left => if (elem_tc.checkComplete) elem_dc else elem_tc
      case Side_position.front =>
        position match {
          case Side_position.up => if (elem_cl.checkComplete) elem_cr else elem_cl
          case Side_position.left => if (elem_tc.checkComplete) elem_dc else elem_tc
          case Side_position.right => if (elem_tc.checkComplete) elem_dc else elem_tc
          case Side_position.down => if (elem_cl.checkComplete) elem_cr else elem_cl
        }
      case Side_position.right => if (elem_tc.checkComplete) elem_dc else elem_tc
      case Side_position.back =>
        position match {
          case Side_position.up => if (elem_cl.checkComplete) elem_cr else elem_cl
          case Side_position.left => if (elem_tc.checkComplete) elem_dc else elem_tc
          case Side_position.right => if (elem_tc.checkComplete) elem_dc else elem_tc
          case Side_position.down => if (elem_cl.checkComplete) elem_cr else elem_cl
        }
      case Side_position.down => if (elem_cl.checkComplete) elem_cr else elem_cl
    }
  }
  def getNextRequiredSideElemForSecondCrestFinalStep: Elem_side = {
    allSideElems.filter(elem => elem.target_pos == elem.current_pos).head
  }
  def getStateForOppositeSide(): (OppositeState, Array[String]) = {
    val allElemState = (for (elem <- allAngleElems) yield elem.getCurrentPos).sorted
    collectionOppositeSideFullCompleteState(allElemState(0),
      allElemState(1), allElemState(2), allElemState(3), position)
  }
  def checkFridrihF2L(startSide: Side_position, otherSide: Side_position): Boolean = {
    startSide match {
      case Side_position.up =>
        otherSide match {
          case Side_position.left =>
            position match {
              case Side_position.front => if (elem_tl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.back => if (elem_tr.checkComplete && elem_cr.checkComplete) true else false
            }
          case Side_position.front =>
            position match {
              case Side_position.right => if (elem_tl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.left => if (elem_tr.checkComplete && elem_cr.checkComplete) true else false
            }
          case Side_position.right =>
            position match {
              case Side_position.back => if (elem_tl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.front => if (elem_tr.checkComplete && elem_cr.checkComplete) true else false
            }
          case Side_position.back =>
            position match {
              case Side_position.left => if (elem_tl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.right => if (elem_tr.checkComplete && elem_cr.checkComplete) true else false
            }
        }
      case Side_position.left =>
        otherSide match {
          case Side_position.up =>
            position match {
              case Side_position.front => if (elem_tl.checkComplete && elem_tc.checkComplete) true else false
              case Side_position.back => if (elem_tr.checkComplete && elem_tc.checkComplete) true else false
            }
          case Side_position.front =>
            position match {
              case Side_position.up => if (elem_dl.checkComplete && elem_dc.checkComplete) true else false
              case Side_position.down => if (elem_tl.checkComplete && elem_tc.checkComplete) true else false
            }
          case Side_position.down =>
            position match {
              case Side_position.front => if (elem_dl.checkComplete && elem_dc.checkComplete) true else false
              case Side_position.back => if (elem_dr.checkComplete && elem_dc.checkComplete) true else false
            }
          case Side_position.back =>
            position match {
              case Side_position.up => if (elem_tl.checkComplete && elem_tc.checkComplete) true else false
              case Side_position.down => if (elem_dl.checkComplete && elem_dc.checkComplete) true else false
            }
        }
      case Side_position.front =>
        otherSide match {
          case Side_position.up =>
            position match {
              case Side_position.left => if (elem_tr.checkComplete && elem_tc.checkComplete) true else false
              case Side_position.right => if (elem_tl.checkComplete && elem_tc.checkComplete) true else false
            }
          case Side_position.right =>
            position match {
              case Side_position.up => if (elem_dr.checkComplete && elem_cr.checkComplete) true else false
              case Side_position.down => if (elem_tr.checkComplete && elem_cr.checkComplete) true else false
            }
          case Side_position.down =>
            position match {
              case Side_position.left => if (elem_dr.checkComplete && elem_dc.checkComplete) true else false
              case Side_position.right => if (elem_dl.checkComplete && elem_dc.checkComplete) true else false
            }
          case Side_position.left =>
            position match {
              case Side_position.up => if (elem_dl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.down => if (elem_tl.checkComplete && elem_cl.checkComplete) true else false
            }
        }
      case Side_position.right =>
        otherSide match {
          case Side_position.up =>
            position match {
              case Side_position.front => if (elem_tr.checkComplete && elem_tc.checkComplete) true else false
              case Side_position.back => if (elem_tl.checkComplete && elem_tc.checkComplete) true else false
            }
          case Side_position.back =>
            position match {
              case Side_position.up => if (elem_tr.checkComplete && elem_tc.checkComplete) true else false
              case Side_position.down => if (elem_dr.checkComplete && elem_dc.checkComplete) true else false
            }
          case Side_position.down =>
            position match {
              case Side_position.front => if (elem_dr.checkComplete && elem_dc.checkComplete) true else false
              case Side_position.back => if (elem_dl.checkComplete && elem_dc.checkComplete) true else false
            }
          case Side_position.front =>
            position match {
              case Side_position.up => if (elem_dr.checkComplete && elem_dc.checkComplete) true else false
              case Side_position.down => if (elem_tr.checkComplete && elem_tc.checkComplete) true else false
            }
        }
      case Side_position.back =>
        otherSide match {
          case Side_position.up =>
            position match {
              case Side_position.right => if (elem_tr.checkComplete && elem_tc.checkComplete) true else false
              case Side_position.left => if (elem_tl.checkComplete && elem_tc.checkComplete) true else false
            }
          case Side_position.left =>
            position match {
              case Side_position.up => if (elem_tl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.down => if (elem_dl.checkComplete && elem_cl.checkComplete) true else false
            }
          case Side_position.down =>
            position match {
              case Side_position.left => if (elem_tl.checkComplete && elem_dc.checkComplete) true else false
              case Side_position.right => if (elem_tr.checkComplete && elem_dc.checkComplete) true else false
            }
          case Side_position.right =>
            position match {
              case Side_position.up => if (elem_tr.checkComplete && elem_cr.checkComplete) true else false
              case Side_position.down => if (elem_dr.checkComplete && elem_cr.checkComplete) true else false
            }
        }
      case Side_position.down =>
        otherSide match {
          case Side_position.left =>
            position match {
              case Side_position.front => if (elem_dl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.back => if (elem_dr.checkComplete && elem_cr.checkComplete) true else false
            }
          case Side_position.front =>
            position match {
              case Side_position.left => if (elem_dr.checkComplete && elem_cr.checkComplete) true else false
              case Side_position.right => if (elem_dl.checkComplete && elem_cl.checkComplete) true else false
            }
          case Side_position.right =>
            position match {
              case Side_position.front => if (elem_dr.checkComplete && elem_cr.checkComplete) true else false
              case Side_position.back => if (elem_dl.checkComplete && elem_cl.checkComplete) true else false
            }
          case Side_position.back =>
            position match {
              case Side_position.left => if (elem_dl.checkComplete && elem_cl.checkComplete) true else false
              case Side_position.right => if (elem_dr.checkComplete && elem_cr.checkComplete) true else false
            }
        }
    }
  }
  def getAngleTargetPositionF2L(firstSide: Side, secondSide: Side): Angle_elem_position = {
    position match {
      case Side_position.up =>
        firstSide.getPosition match {
          case Side_position.left =>
            secondSide.getPosition match {
              case Side_position.front => elem_dl.getCurrentPos
              case Side_position.back => elem_tl.getCurrentPos
            }
          case Side_position.front =>
            secondSide.getPosition match {
              case Side_position.left => elem_dl.getCurrentPos
              case Side_position.right => elem_dr.getCurrentPos
            }
          case Side_position.right =>
            secondSide.getPosition match {
              case Side_position.front => elem_dr.getCurrentPos
              case Side_position.back => elem_tr.getCurrentPos
            }
          case Side_position.back =>
            secondSide.getPosition match {
              case Side_position.left => elem_tl.getCurrentPos
              case Side_position.right => elem_tr.getCurrentPos
            }
        }
      case Side_position.left =>
        firstSide.getPosition match {
          case Side_position.up =>
            secondSide.getPosition match {
              case Side_position.front => elem_tr. getCurrentPos
              case Side_position.back => elem_tl.getCurrentPos
            }
          case Side_position.front =>
            secondSide.getPosition match {
              case Side_position.up => elem_tr.getCurrentPos
              case Side_position.down => elem_dr.getCurrentPos
            }
          case Side_position.down =>
            secondSide.getPosition match {
              case Side_position.front => elem_dr.getCurrentPos
              case Side_position.back => elem_dl.getCurrentPos
            }
          case Side_position.back =>
            secondSide.getPosition match {
              case Side_position.up => elem_tl.getCurrentPos
              case Side_position.down => elem_dl.getCurrentPos
            }
        }
      case Side_position.front =>
        firstSide.getPosition match {
          case Side_position.left =>
            secondSide.getPosition match {
              case Side_position.up => elem_tl.getCurrentPos
              case Side_position.down => elem_dl.getCurrentPos
            }
          case Side_position.up =>
            secondSide.getPosition match {
              case Side_position.left => elem_tl.getCurrentPos
              case Side_position.right => elem_tr.getCurrentPos
            }
          case Side_position.right =>
            secondSide.getPosition match {
              case Side_position.up => elem_tr.getCurrentPos
              case Side_position.down => elem_dr.getCurrentPos
            }
          case Side_position.down =>
            secondSide.getPosition match {
              case Side_position.left => elem_dl.getCurrentPos
              case Side_position.right => elem_dr.getCurrentPos
            }
        }
      case Side_position.right =>
        firstSide.getPosition match {
          case Side_position.up =>
            secondSide.getPosition match {
              case Side_position.front => elem_tl.getCurrentPos
              case Side_position.back => elem_tr.getCurrentPos
            }
          case Side_position.front =>
            secondSide.getPosition match {
              case Side_position.up => elem_tl.getCurrentPos
              case Side_position.down => elem_dl.getCurrentPos
            }
          case Side_position.down =>
            secondSide.getPosition match {
              case Side_position.front => elem_dl.getCurrentPos
              case Side_position.back => elem_dr.getCurrentPos
            }
          case Side_position.back =>
            secondSide.getPosition match {
              case Side_position.up => elem_tr.getCurrentPos
              case Side_position.down => elem_dr.getCurrentPos
            }
        }
      case Side_position.back =>
        firstSide.getPosition match {
          case Side_position.left =>
            secondSide.getPosition match {
              case Side_position.up => elem_tr.getCurrentPos
              case Side_position.down => elem_dr.getCurrentPos
            }
          case Side_position.up =>
            secondSide.getPosition match {
              case Side_position.left => elem_tr.getCurrentPos
              case Side_position.right => elem_tl.getCurrentPos
            }
          case Side_position.right =>
            secondSide.getPosition match {
              case Side_position.up => elem_tl.getCurrentPos
              case Side_position.down => elem_dl.getCurrentPos
            }
          case Side_position.down =>
            secondSide.getPosition match {
              case Side_position.left => elem_dl.getCurrentPos
              case Side_position.right => elem_dr.getCurrentPos
            }
        }
      case Side_position.down =>
        firstSide.getPosition match {
          case Side_position.left =>
            secondSide.getPosition match {
              case Side_position.front => elem_tl.getCurrentPos
              case Side_position.back => elem_dl.getCurrentPos
            }
          case Side_position.front =>
            secondSide.getPosition match {
              case Side_position.left => elem_tl.getCurrentPos
              case Side_position.right => elem_tr.getCurrentPos
            }
          case Side_position.right =>
            secondSide.getPosition match {
              case Side_position.front => elem_tr.getCurrentPos
              case Side_position.back => elem_dr.getCurrentPos
            }
          case Side_position.back =>
            secondSide.getPosition match {
              case Side_position.left => elem_dl.getCurrentPos
              case Side_position.right => elem_dr.getCurrentPos
            }
        }
    }
  }
  def getSideTargetPositionF2L(otherSide: Side_position): Side_elem_position = {
    position match {
      case Side_position.up =>
        otherSide match {
          case Side_position.left => elem_cl.getCurrentPos
          case Side_position.front => elem_dc.getCurrentPos
          case Side_position.right => elem_cr.getCurrentPos
          case Side_position.back => elem_tc.getCurrentPos
        }
      case Side_position.left =>
        otherSide match {
          case Side_position.up => elem_tc.getCurrentPos
          case Side_position.front => elem_cr.getCurrentPos
          case Side_position.down => elem_dc.getCurrentPos
          case Side_position.back => elem_cl.getCurrentPos
        }
      case Side_position.front =>
        otherSide match {
          case Side_position.left => elem_cl.getCurrentPos
          case Side_position.up => elem_tc.getCurrentPos
          case Side_position.right => elem_cr.getCurrentPos
          case Side_position.down => elem_dc.getCurrentPos
        }
      case Side_position.right =>
        otherSide match {
          case Side_position.up => elem_tc.getCurrentPos
          case Side_position.front => elem_cl.getCurrentPos
          case Side_position.down => elem_dc.getCurrentPos
          case Side_position.back => elem_cr.getCurrentPos
        }
      case Side_position.back =>
        otherSide match {
          case Side_position.left => elem_cr.getCurrentPos
          case Side_position.up => elem_tc.getCurrentPos
          case Side_position.right => elem_cl.getCurrentPos
          case Side_position.down => elem_dc.getCurrentPos
        }
      case Side_position.down =>
        otherSide match {
          case Side_position.left => elem_cl.getCurrentPos
          case Side_position.front => elem_tc.getCurrentPos
          case Side_position.right => elem_cr.getCurrentPos
          case Side_position.back => elem_dc.getCurrentPos
        }
    }
  }
  def getElem(name: String): Option[Elem] = {
    Option(allElems.filter(elem => elem.getName == name).head)
  }
  def checkToHaveElem(name: String): Boolean = {
    allElems.exists(elem => elem.getName == name)
  }
  def getCenterElem(): Elem_center = elem_cc
  def getCenterUpElem(): Elem_side = elem_tc
  def getCenterDownElem(): Elem_side = elem_dc
  def getCenterLeftElem(): Elem_side = elem_cl
  def getCenterRightElem(): Elem_side = elem_cr
  def getRightDownElem(): Elem_angle = elem_dr
  def getAllElems() = allElems2
  def checkCOLL_Complete(): Boolean = {
//    println(s"checkCOLL: side: ${(for (elem <- allSideElems) yield elem.get_color(Side_position.up)).mkString(", ")}; angle: ${(for (elem <- allAngleElems) yield elem.get_color(Side_position.up)).mkString(", ")}")
//    if (allSideElems.exists(elem => elem.getCurrentPos.toString.apply(2) != '1') ||
//      allAngleElems.exists(elem => elem.getCurrentPos.toString.apply(3) != '1')) false else true
    if (allSideElems.exists(elem => elem.getCurrentPos.toString.apply(2) != '1') ||
      allAngleElems.exists(elem => elem.checkComplete == false)) false else true
  }
  def checkCOLL_CompleteOnlyColor(): Boolean = {
    //    println(s"checkCOLL_CompleteOnlyColor: side: ${(for (elem <- allSideElems) yield elem.get_color(Side_position.up)).mkString(", ")}; angle: ${(for (elem <- allAngleElems) yield elem.get_color(Side_position.up)).mkString(", ")}")
    if (allSideElems.exists(elem => elem.getCurrentPos.toString.apply(2) != '1') ||
      allAngleElems.exists(elem => elem.getCurrentPos.toString.apply(3) != '1')) false else true
  }
}

object Side extends Side_elem_names_table with Collection_opposite_side_full_complete_state
