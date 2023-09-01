package src

import src.Elem_colors.Elem_colors

abstract class Elem(val name: String,
                    val color_1: Elem_colors) {
  def getName: String
  def getCurrentPos: Any
  def getTargetPos: Any

  def x_front(colorSequence: Array[Elem_colors]): Unit
  def x_back(colorSequence: Array[Elem_colors]): Unit
  def y_front(colorSequence: Array[Elem_colors]): Unit
  def y_back(colorSequence: Array[Elem_colors]): Unit
  def z_front(colorSequence: Array[Elem_colors]): Unit
  def z_back(colorSequence: Array[Elem_colors]): Unit
}
