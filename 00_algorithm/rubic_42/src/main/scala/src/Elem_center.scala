package src

import src.Center_elem_position.{Center_elem_position, ll, uu, ff, rr, bb, dd}
import src.Elem_colors.Elem_colors

class Elem_center(name: String,
                  color_1: Elem_colors,
                  val target_pos: Center_elem_position,
                  var current_pos: Center_elem_position)
  extends Elem(name, color_1) {
  def get_color(): Char = color_1.toString.head
  def getName: String = name
  def getCurrentPos: Center_elem_position = current_pos
  def getTargetPos: Center_elem_position = target_pos
  def checkComplete: Boolean = if (target_pos == current_pos) true else false

  def x_front(colorSequence: Array[Elem_colors]): Unit = {
    // front -> up
    current_pos match {
      case Center_elem_position.uu => current_pos = bb
      case Center_elem_position.ll => current_pos = ll
      case Center_elem_position.ff => current_pos = uu
      case Center_elem_position.rr => current_pos = rr
      case Center_elem_position.bb => current_pos = dd
      case Center_elem_position.dd => current_pos = ff
    }
  }
  def x_back(colorSequence: Array[Elem_colors]): Unit = {
    // front -> down
    current_pos match {
      case Center_elem_position.uu => current_pos = ff
      case Center_elem_position.ll => current_pos = ll
      case Center_elem_position.ff => current_pos = dd
      case Center_elem_position.rr => current_pos = rr
      case Center_elem_position.bb => current_pos = uu
      case Center_elem_position.dd => current_pos = bb
    }
  }
  def y_front(colorSequence: Array[Elem_colors]): Unit = {
    // front -> left
    current_pos match {
      case Center_elem_position.uu => current_pos = uu
      case Center_elem_position.ll => current_pos = bb
      case Center_elem_position.ff => current_pos = ll
      case Center_elem_position.rr => current_pos = ff
      case Center_elem_position.bb => current_pos = rr
      case Center_elem_position.dd => current_pos = dd
    }
  }
  def y_back(colorSequence: Array[Elem_colors]): Unit = {
    // front -> right
    current_pos match {
      case Center_elem_position.uu => current_pos = uu
      case Center_elem_position.ll => current_pos = ff
      case Center_elem_position.ff => current_pos = rr
      case Center_elem_position.rr => current_pos = bb
      case Center_elem_position.bb => current_pos = ll
      case Center_elem_position.dd => current_pos = dd
    }
  }
  def z_front(colorSequence: Array[Elem_colors]): Unit = {
    // up -> right
    current_pos match {
      case Center_elem_position.uu => current_pos = rr
      case Center_elem_position.ll => current_pos = uu
      case Center_elem_position.ff => current_pos = ff
      case Center_elem_position.rr => current_pos = dd
      case Center_elem_position.bb => current_pos = bb
      case Center_elem_position.dd => current_pos = ll
    }
  }
  def z_back(colorSequence: Array[Elem_colors]): Unit = {
    // up -> left
    current_pos match {
      case Center_elem_position.uu => current_pos = ll
      case Center_elem_position.ll => current_pos = dd
      case Center_elem_position.ff => current_pos = ff
      case Center_elem_position.rr => current_pos = uu
      case Center_elem_position.bb => current_pos = bb
      case Center_elem_position.dd => current_pos = rr
    }
  }
}
