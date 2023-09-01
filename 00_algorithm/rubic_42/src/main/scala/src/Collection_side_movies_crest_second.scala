/*
    Collection movies for side elem for second crest
    (<current_position>, <target_position>, <start_side>) -> <needed_movies>

    target positions => xx1
    current positions => xx(1, 2)

    R U R' U R U2 R' U: Change fu and lu
    B U B' U B U2 B' U: Change fu and ru
 */

package src

trait Collection_side_movies_crest_second {
  val collectionSideMoviesCrestSecond = Map(
  // start side: up
    (Side_elem_position.lu1, Side_elem_position.fu1, Side_position.up) -> Array("R", "U", "R'", "U", "R", "U2", "R'", "U"),
    (Side_elem_position.ru1, Side_elem_position.fu1, Side_position.up) -> Array("B", "U", "B'", "U", "B", "U2", "B'", "U"),
    (Side_elem_position.bu1, Side_elem_position.fu1, Side_position.up) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fu1, Side_elem_position.ru1, Side_position.up) -> Array("B", "U", "B'", "U", "B", "U2", "B'", "U"),
    (Side_elem_position.lu1, Side_elem_position.ru1, Side_position.up) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bu1, Side_elem_position.ru1, Side_position.up) -> Array("L", "U", "L'", "U", "L", "U2", "L'", "U"),
    (Side_elem_position.fu1, Side_elem_position.lu1, Side_position.up) -> Array("R", "U", "R'", "U", "R", "U2", "R'", "U"),
    (Side_elem_position.ru1, Side_elem_position.lu1, Side_position.up) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bu1, Side_elem_position.lu1, Side_position.up) -> Array("F", "U", "F'", "U", "F", "U2", "F'", "U"),
    (Side_elem_position.fu1, Side_elem_position.bu1, Side_position.up) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.ru1, Side_elem_position.bu1, Side_position.up) -> Array("L", "U", "L'", "U", "L", "U2", "L'", "U"),
    (Side_elem_position.lu1, Side_elem_position.bu1, Side_position.up) -> Array("F", "U", "F'", "U", "F", "U2", "F'", "U"),
    // start side: left
    (Side_elem_position.ld1, Side_elem_position.fl1, Side_position.left) -> Array("U", "L", "U'", "L", "U", "L2", "U'", "L"),
    (Side_elem_position.lu1, Side_elem_position.fl1, Side_position.left) -> Array("B", "L", "B'", "L", "B", "L2", "B'", "L"),
    (Side_elem_position.br1, Side_elem_position.fl1, Side_position.left) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fl1, Side_elem_position.ld1, Side_position.left) -> Array("U", "L", "U'", "L", "U", "L2", "U'", "L"),
    (Side_elem_position.lu1, Side_elem_position.ld1, Side_position.left) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.br1, Side_elem_position.ld1, Side_position.left) -> Array("F", "L", "F'", "L", "F", "L2", "F'", "L"),
    (Side_elem_position.fl1, Side_elem_position.lu1, Side_position.left) -> Array("B", "L", "B'", "L", "B", "L2", "B'", "L"),
    (Side_elem_position.ld1, Side_elem_position.lu1, Side_position.left) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.br1, Side_elem_position.lu1, Side_position.left) -> Array("D", "L", "D'", "L", "D", "L2", "D'", "L"),
    (Side_elem_position.fl1, Side_elem_position.br1, Side_position.left) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.ld1, Side_elem_position.br1, Side_position.left) -> Array("F", "L", "F'", "L", "F", "L2", "F'", "L"),
    (Side_elem_position.lu1, Side_elem_position.br1, Side_position.left) -> Array("D", "L", "D'", "L", "D", "L2", "D'", "L"),
    // start side: front
    (Side_elem_position.fl1, Side_elem_position.fd1, Side_position.front) -> Array("R", "F", "R'", "F", "R", "F2", "R'", "F"),
    (Side_elem_position.fr1, Side_elem_position.fd1, Side_position.front) -> Array("U", "F", "U'", "F", "U", "F2", "U'", "F"),
    (Side_elem_position.fu1, Side_elem_position.fd1, Side_position.front) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fd1, Side_elem_position.fu1, Side_position.front) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fl1, Side_elem_position.fu1, Side_position.front) -> Array("D", "F", "D'", "F", "D", "F2", "D'", "F"),
    (Side_elem_position.fr1, Side_elem_position.fu1, Side_position.front) -> Array("L", "F", "L'", "F", "L", "F2", "L'", "F"),
    (Side_elem_position.fd1, Side_elem_position.fl1, Side_position.front) -> Array("R", "F", "R'", "F", "R", "F2", "R'", "F"),
    (Side_elem_position.fu1, Side_elem_position.fl1, Side_position.front) -> Array("D", "F", "D'", "F", "D", "F2", "D'", "F"),
    (Side_elem_position.fr1, Side_elem_position.fl1, Side_position.front) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fd1, Side_elem_position.fr1, Side_position.front) -> Array("U", "F", "U'", "F", "U", "F2", "U'", "F"),
    (Side_elem_position.fu1, Side_elem_position.fr1, Side_position.front) -> Array("L", "F", "L'", "F", "L", "F2", "L'", "F"),
    (Side_elem_position.fl1, Side_elem_position.fr1, Side_position.front) -> Array("", "", "", "", "", "", "", ""),
    // start side: right
    (Side_elem_position.ru1, Side_elem_position.fr1, Side_position.right) -> Array("D", "R", "D'", "R", "D", "R2", "D'", "R"),
    (Side_elem_position.rd1, Side_elem_position.fr1, Side_position.right) -> Array("B", "R", "B'", "R", "B", "R2", "B'", "R"),
    (Side_elem_position.bl1, Side_elem_position.fr1, Side_position.right) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fr1, Side_elem_position.ru1, Side_position.right) -> Array("D", "R", "D'", "R", "D", "R2", "D'", "R"),
    (Side_elem_position.rd1, Side_elem_position.ru1, Side_position.right) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bl1, Side_elem_position.ru1, Side_position.right) -> Array("F", "R", "F'", "R", "F", "R2", "F'", "R"),
    (Side_elem_position.fr1, Side_elem_position.rd1, Side_position.right) -> Array("B", "R", "B'", "R", "B", "R2", "B'", "R"),
    (Side_elem_position.ru1, Side_elem_position.rd1, Side_position.right) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bl1, Side_elem_position.rd1, Side_position.right) -> Array("U", "R", "U'", "R", "U", "R2", "U'", "R"),
    (Side_elem_position.fr1, Side_elem_position.bl1, Side_position.right) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.ru1, Side_elem_position.bl1, Side_position.right) -> Array("F", "R", "F'", "R", "F", "R2", "F'", "R"),
    (Side_elem_position.rd1, Side_elem_position.bl1, Side_position.right) -> Array("U", "R", "U'", "R", "U", "R2", "U'", "R"),
    // start side: back
    (Side_elem_position.br1, Side_elem_position.bu1, Side_position.back) -> Array("R", "B", "R'", "B", "R", "B2", "R'", "B"),
    (Side_elem_position.bl1, Side_elem_position.bu1, Side_position.back) -> Array("D", "B", "D'", "B", "D", "B2", "D'", "B"),
    (Side_elem_position.bd1, Side_elem_position.bu1, Side_position.back) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bu1, Side_elem_position.br1, Side_position.back) -> Array("R", "B", "R'", "B", "R", "B2", "R'", "B"),
    (Side_elem_position.bl1, Side_elem_position.br1, Side_position.back) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bd1, Side_elem_position.br1, Side_position.back) -> Array("F", "B", "F'", "B", "F", "B2", "F'", "B"),
    (Side_elem_position.bu1, Side_elem_position.bl1, Side_position.back) -> Array("D", "B", "D'", "B", "D", "B2", "D'", "B"),
    (Side_elem_position.br1, Side_elem_position.bl1, Side_position.back) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bd1, Side_elem_position.bl1, Side_position.back) -> Array("L", "B", "L'", "B", "L", "B2", "L'", "B"),
    (Side_elem_position.bu1, Side_elem_position.bd1, Side_position.back) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.bl1, Side_elem_position.bd1, Side_position.back) -> Array("L", "B", "L'", "B", "L", "B2", "L'", "B"),
    (Side_elem_position.br1, Side_elem_position.bd1, Side_position.back) -> Array("F", "B", "F'", "B", "F", "B2", "F'", "B"),
    // start side: down
    (Side_elem_position.bd1, Side_elem_position.ld1, Side_position.down) -> Array("R", "D", "R'", "D", "R", "D2", "R'", "D"),
    (Side_elem_position.fd1, Side_elem_position.ld1, Side_position.down) -> Array("B", "D", "L'", "D", "L", "D2", "L'", "D"),
    (Side_elem_position.rd1, Side_elem_position.ld1, Side_position.down) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.ld1, Side_elem_position.bd1, Side_position.down) -> Array("R", "D", "R'", "D", "R", "D2", "R'", "D"),
    (Side_elem_position.fd1, Side_elem_position.bd1, Side_position.down) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.rd1, Side_elem_position.bd1, Side_position.down) -> Array("F", "D", "F'", "D", "F", "D2", "F'", "D"),
    (Side_elem_position.bd1, Side_elem_position.fd1, Side_position.down) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.ld1, Side_elem_position.fd1, Side_position.down) -> Array("B", "D", "L'", "D", "L", "D2", "L'", "D"),
    (Side_elem_position.rd1, Side_elem_position.fd1, Side_position.down) -> Array("L", "D", "L'", "D", "L", "D2", "L'", "D"),
    (Side_elem_position.ld1, Side_elem_position.rd1, Side_position.down) -> Array("", "", "", "", "", "", "", ""),
    (Side_elem_position.fd1, Side_elem_position.rd1, Side_position.down) -> Array("L", "D", "L'", "D", "L", "D2", "L'", "D"),
    (Side_elem_position.bd1, Side_elem_position.rd1, Side_position.down) -> Array("F", "D", "F'", "D", "F", "D2", "F'", "D")
  )
}
