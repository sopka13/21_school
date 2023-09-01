/*
      Collection for get complete opposite cross after F2L step

      <fu_state>, <lu_state>, <bu_state>, <ru_state> -> Array[String](<movies>)
 */

package src

trait Collection_opposite_cross_after_F2L {
  val collectionOppositeCrossAfterF2L = Map(
    (Side_elem_position.fu1, Side_elem_position.lu1, Side_elem_position.bu1, Side_elem_position.ru1) -> Array(""),// OK
    (Side_elem_position.fu2, Side_elem_position.lu1, Side_elem_position.bu1, Side_elem_position.ru1) -> Array("F", "R", "U", "R'", "U'", "F'"),

    (Side_elem_position.fu1, Side_elem_position.lu2, Side_elem_position.bu1, Side_elem_position.ru1) -> Array("U'", "F", "R", "U", "R'", "U'", "F'"),
    (Side_elem_position.fu2, Side_elem_position.lu2, Side_elem_position.bu1, Side_elem_position.ru1) -> Array("U'", "F", "U", "R", "U'", "R'", "F'"),

    (Side_elem_position.fu1, Side_elem_position.lu1, Side_elem_position.bu2, Side_elem_position.ru1) -> Array("U2", "F", "R", "U", "R'", "U'", "F'"),
    (Side_elem_position.fu2, Side_elem_position.lu1, Side_elem_position.bu2, Side_elem_position.ru1) -> Array("F", "R", "U", "R'", "U'", "F'"),

    (Side_elem_position.fu1, Side_elem_position.lu2, Side_elem_position.bu2, Side_elem_position.ru1) -> Array("U2", "F", "U", "R", "U'", "R'", "F'"),
    (Side_elem_position.fu2, Side_elem_position.lu2, Side_elem_position.bu2, Side_elem_position.ru1) -> Array(""), // impossible situation

    (Side_elem_position.fu1, Side_elem_position.lu1, Side_elem_position.bu1, Side_elem_position.ru2) -> Array("U", "F", "R", "U", "R'", "U'", "F'"),
    (Side_elem_position.fu2, Side_elem_position.lu1, Side_elem_position.bu1, Side_elem_position.ru2) -> Array("F", "U", "R", "U'", "R'", "F'"),

    (Side_elem_position.fu1, Side_elem_position.lu2, Side_elem_position.bu1, Side_elem_position.ru2) -> Array("U", "F", "R", "U", "R'", "U'", "F'"),
    (Side_elem_position.fu2, Side_elem_position.lu2, Side_elem_position.bu1, Side_elem_position.ru2) -> Array(""),// impossible situation

    (Side_elem_position.fu1, Side_elem_position.lu1, Side_elem_position.bu2, Side_elem_position.ru2) -> Array("U", "F", "U", "R", "U'", "R'", "F'"),
    (Side_elem_position.fu2, Side_elem_position.lu1, Side_elem_position.bu2, Side_elem_position.ru2) -> Array(""),// impossible situation

    (Side_elem_position.fu1, Side_elem_position.lu2, Side_elem_position.bu2, Side_elem_position.ru2) -> Array(""),// impossible situation
    (Side_elem_position.fu2, Side_elem_position.lu2, Side_elem_position.bu2, Side_elem_position.ru2) -> Array("F", "R", "U", "R'", "U'", "F'", "U2", "F", "R", "U", "R'", "U'", "R", "U", "R'", "U'", "F'"),
  )
}
