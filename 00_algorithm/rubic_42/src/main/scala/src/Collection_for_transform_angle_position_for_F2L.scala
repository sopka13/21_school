/*
    Collection for transform angle position for F2L step Fridrih

    (startSidePosition, otherSidePosition, currentAngleElemPos) -> angleElemPos
 */

package src

class Collection_for_transform_angle_position_for_F2L {
  val collectionForTransformAnglePositionForF2L = Map(
    // start side: up
    (Side_position.up, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.left, Angle_elem_position.bdr1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.left, Angle_elem_position.fdl1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.left, Angle_elem_position.fdr1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.left, Angle_elem_position.bdl1) -> Angle_elem_position.fdr1,

    (Side_position.up, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.up, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.up, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.up, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    // start side: left
    (Side_position.left, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.left, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.left, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.left, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.left, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    // start side: front
    (Side_position.front, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.front, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.front, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.front, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.front, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    // start side: right
    (Side_position.right, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.right, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.right, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.right, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.right, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    // start side: back
    (Side_position.back, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.up, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.back, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.back, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.down, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.back, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.back, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    // start side: down
    (Side_position.down, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.left, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.down, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.front, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.down, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.right, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

    (Side_position.down, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,
    (Side_position.down, Side_position.back, Angle_elem_position.bur1) -> Angle_elem_position.fdr1,

  )
}
