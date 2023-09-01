/*
    Collection movies for side elem for prepare F2L
    <current_position> -> <needed_movies>

    current positions => xx(1, 2)
 */

package src

trait Collection_side_movies_for_prepare_F2L {
  val collectionSideMoviesForPrapareF2L = Map(
    Side_elem_position.fl1 -> Array("F", "U", "F'"),
    Side_elem_position.fl2 -> Array("F", "U", "F'"),
    Side_elem_position.br1 -> Array("B'", "U", "B"),
    Side_elem_position.br2 -> Array("B'", "U", "B"),
    Side_elem_position.bl1 -> Array("B", "U", "B'"),
    Side_elem_position.bl2 -> Array("B", "U", "B'")
  )
}
