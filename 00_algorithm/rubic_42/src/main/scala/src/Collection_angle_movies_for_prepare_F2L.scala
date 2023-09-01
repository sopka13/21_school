/*
    Collection movies for angle elem for prepare F2L
    <current_position> -> <needed_movies>

    current positions => xxx(1, 2, 3)
 */

package src

trait Collection_angle_movies_for_prepare_F2L {
  val collectionAngleMoviesForPrepareF2L = Map(
    Angle_elem_position.fdl1 -> Array("F", "U", "F'"),
    Angle_elem_position.fdl2 -> Array("F", "U", "F'"),
    Angle_elem_position.fdl3 -> Array("F", "U", "F'"),
    Angle_elem_position.bdr1 -> Array("B'", "U", "B"),
    Angle_elem_position.bdr2 -> Array("B'", "U", "B"),
    Angle_elem_position.bdr3 -> Array("B'", "U", "B"),
    Angle_elem_position.bdl1 -> Array("B", "U", "B'"),
    Angle_elem_position.bdl2 -> Array("B", "U", "B'"),
    Angle_elem_position.bdl3 -> Array("B", "U", "B'"),
  )
}
