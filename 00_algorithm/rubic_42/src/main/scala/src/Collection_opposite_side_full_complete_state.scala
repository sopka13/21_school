/*
    Collection for get opposite side full state elem for final full solve only one color

    (<state_ul>, <state_ur>, <state_dl>, <state_dr>, <target_side>) -> <opposite_side_state>
 */

package src

import src.Angle_elem_position.Angle_elem_position
import src.OppositeState.OppositeState
import src.Side_position.Side_position

trait Collection_opposite_side_full_complete_state {
  def collectionOppositeSideFullCompleteState(key_1: Angle_elem_position,
                                               key_2: Angle_elem_position,
                                               key_3: Angle_elem_position,
                                               key_4: Angle_elem_position,
                                               side: Side_position): (OppositeState, Array[String]) = {
    if (_collectionOppositeSideFullCompleteState.contains(key_1, key_2, key_3, key_4, side))
      _collectionOppositeSideFullCompleteState(key_1, key_2, key_3, key_4, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_2, key_1, key_3, key_4, side))
      _collectionOppositeSideFullCompleteState(key_2, key_1, key_3, key_4, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_2, key_3, key_1, key_4, side))
      _collectionOppositeSideFullCompleteState(key_2, key_3, key_1, key_4, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_3, key_2, key_1, key_4, side))
      _collectionOppositeSideFullCompleteState(key_3, key_2, key_1, key_4, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_3, key_1, key_2, key_4, side))
      _collectionOppositeSideFullCompleteState(key_3, key_1, key_2, key_4, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_1, key_3, key_2, key_4, side))
      _collectionOppositeSideFullCompleteState(key_1, key_3, key_2, key_4, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_1, key_2, key_4, key_3, side))
      _collectionOppositeSideFullCompleteState(key_1, key_2, key_4, key_3, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_2, key_1, key_4, key_3, side))
      _collectionOppositeSideFullCompleteState(key_2, key_1, key_4, key_3, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_2, key_4, key_1, key_3, side))
      _collectionOppositeSideFullCompleteState(key_2, key_4, key_1, key_3, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_4, key_2, key_1, key_3, side))
      _collectionOppositeSideFullCompleteState(key_4, key_2, key_1, key_3, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_4, key_1, key_2, key_3, side))
      _collectionOppositeSideFullCompleteState(key_4, key_1, key_2, key_3, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_1, key_4, key_2, key_3, side))
      _collectionOppositeSideFullCompleteState(key_1, key_4, key_2, key_3, side)

    else if (_collectionOppositeSideFullCompleteState.contains(key_1, key_4, key_3, key_2, side))
      _collectionOppositeSideFullCompleteState(key_1, key_4, key_3, key_2, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_4, key_1, key_3, key_2, side))
      _collectionOppositeSideFullCompleteState(key_4, key_1, key_3, key_2, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_4, key_3, key_1, key_2, side))
      _collectionOppositeSideFullCompleteState(key_4, key_3, key_1, key_2, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_3, key_4, key_1, key_2, side))
      _collectionOppositeSideFullCompleteState(key_3, key_4, key_1, key_2, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_3, key_1, key_4, key_2, side))
      _collectionOppositeSideFullCompleteState(key_3, key_1, key_4, key_2, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_1, key_3, key_4, key_2, side))
      _collectionOppositeSideFullCompleteState(key_1, key_3, key_4, key_2, side)

    else if (_collectionOppositeSideFullCompleteState.contains(key_4, key_2, key_3, key_1, side))
      _collectionOppositeSideFullCompleteState(key_4, key_2, key_3, key_1, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_2, key_4, key_3, key_1, side))
      _collectionOppositeSideFullCompleteState(key_2, key_4, key_3, key_1, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_2, key_3, key_4, key_1, side))
      _collectionOppositeSideFullCompleteState(key_2, key_3, key_4, key_1, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_3, key_2, key_4, key_1, side))
      _collectionOppositeSideFullCompleteState(key_3, key_2, key_4, key_1, side)
    else if (_collectionOppositeSideFullCompleteState.contains(key_3, key_4, key_2, key_1, side))
      _collectionOppositeSideFullCompleteState(key_3, key_4, key_2, key_1, side)
    else
      _collectionOppositeSideFullCompleteState(key_4, key_3, key_2, key_1, side)

  }
  private val _collectionOppositeSideFullCompleteState = Map(
    // for up side
    (Angle_elem_position.bur1, Angle_elem_position.bul1,
      Angle_elem_position.ful1, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_one, Array("")), // not used
    (Angle_elem_position.bur3, Angle_elem_position.bul2,
      Angle_elem_position.ful2, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.bur3, Angle_elem_position.bul2,
      Angle_elem_position.ful1, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_one, Array("U'")),
    (Angle_elem_position.bur1, Angle_elem_position.bul2,
      Angle_elem_position.ful2, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_one, Array("U2")),
    (Angle_elem_position.bur3, Angle_elem_position.bul1,
      Angle_elem_position.ful2, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_one, Array("U")),

    (Angle_elem_position.bur2, Angle_elem_position.bul3,
      Angle_elem_position.ful3, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_two, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.bul3,
      Angle_elem_position.ful1, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_two, Array("U'")),
    (Angle_elem_position.bur1, Angle_elem_position.bul3,
      Angle_elem_position.ful3, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_two, Array("U2")),
    (Angle_elem_position.bur2, Angle_elem_position.bul1,
      Angle_elem_position.ful3, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_two, Array("U")),

    (Angle_elem_position.bur3, Angle_elem_position.bul1,
      Angle_elem_position.ful1, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_three, Array("")),
    (Angle_elem_position.bur1, Angle_elem_position.bul2,
      Angle_elem_position.ful3, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_three, Array("U'")),
    (Angle_elem_position.bur2, Angle_elem_position.bul1,
      Angle_elem_position.ful1, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_three, Array("U2")),
    (Angle_elem_position.bur1, Angle_elem_position.bul3,
      Angle_elem_position.ful2, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_three, Array("U")),

    (Angle_elem_position.bur3, Angle_elem_position.bul3,
      Angle_elem_position.ful3, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_four, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.bul2,
      Angle_elem_position.ful2, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_four, Array("U")),

    (Angle_elem_position.bur1, Angle_elem_position.bul3,
      Angle_elem_position.ful1, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_five, Array("")),
    (Angle_elem_position.bur1, Angle_elem_position.bul1,
      Angle_elem_position.ful2, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_five, Array("U'")),
    (Angle_elem_position.bur3, Angle_elem_position.bul1,
      Angle_elem_position.ful3, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_five, Array("U2")),
    (Angle_elem_position.bur2, Angle_elem_position.bul2,
      Angle_elem_position.ful1, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_five, Array("U")),

    (Angle_elem_position.bur2, Angle_elem_position.bul2,
      Angle_elem_position.ful3, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_six, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.bul3,
      Angle_elem_position.ful2, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_six, Array("U'")),
    (Angle_elem_position.bur3, Angle_elem_position.bul3,
      Angle_elem_position.ful2, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_six, Array("U2")),
    (Angle_elem_position.bur3, Angle_elem_position.bul2,
      Angle_elem_position.ful3, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_six, Array("U")),

    (Angle_elem_position.bur1, Angle_elem_position.bul1,
      Angle_elem_position.ful3, Angle_elem_position.fur2, Side_position.up) -> (OppositeState.opp_seven, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.bul1,
      Angle_elem_position.ful2, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_seven, Array("U'")),
    (Angle_elem_position.bur3, Angle_elem_position.bul3,
      Angle_elem_position.ful1, Angle_elem_position.fur1, Side_position.up) -> (OppositeState.opp_seven, Array("U2")),
    (Angle_elem_position.bur1, Angle_elem_position.bul2,
      Angle_elem_position.ful1, Angle_elem_position.fur3, Side_position.up) -> (OppositeState.opp_seven, Array("U")),

    // for left side
    (Angle_elem_position.bur1, Angle_elem_position.ful1,
      Angle_elem_position.bdr1, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_one, Array("")), // not used
    (Angle_elem_position.bur3, Angle_elem_position.ful2,
      Angle_elem_position.bdr2, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.bur3, Angle_elem_position.ful2,
      Angle_elem_position.bdr1, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_one, Array("L'")),
    (Angle_elem_position.bur1, Angle_elem_position.ful2,
      Angle_elem_position.bdr2, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_one, Array("L2")),
    (Angle_elem_position.bur3, Angle_elem_position.ful1,
      Angle_elem_position.bdr2, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_one, Array("L")),

    (Angle_elem_position.bur2, Angle_elem_position.ful3,
      Angle_elem_position.bdr3, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_two, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.ful3,
      Angle_elem_position.bdr1, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_two, Array("L'")),
    (Angle_elem_position.bur1, Angle_elem_position.ful3,
      Angle_elem_position.bdr3, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_two, Array("L2")),
    (Angle_elem_position.bur2, Angle_elem_position.ful1,
      Angle_elem_position.bdr3, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_two, Array("L")),

    (Angle_elem_position.bur3, Angle_elem_position.ful1,
      Angle_elem_position.bdr1, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_three, Array("")),
    (Angle_elem_position.bur1, Angle_elem_position.ful2,
      Angle_elem_position.bdr3, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_three, Array("L'")),
    (Angle_elem_position.bur2, Angle_elem_position.ful1,
      Angle_elem_position.bdr1, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_three, Array("L2")),
    (Angle_elem_position.bur1, Angle_elem_position.ful3,
      Angle_elem_position.bdr2, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_three, Array("L")),

    (Angle_elem_position.bur2, Angle_elem_position.ful3,
      Angle_elem_position.bdr2, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_four, Array("")),
    (Angle_elem_position.bur3, Angle_elem_position.ful2,
      Angle_elem_position.bdr3, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_four, Array("L")),

    (Angle_elem_position.bur1, Angle_elem_position.ful3,
      Angle_elem_position.bdr1, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_five, Array("")),
    (Angle_elem_position.bur1, Angle_elem_position.ful1,
      Angle_elem_position.bdr2, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_five, Array("L'")),
    (Angle_elem_position.bur3, Angle_elem_position.ful1,
      Angle_elem_position.bdr3, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_five, Array("L2")),
    (Angle_elem_position.bur2, Angle_elem_position.ful2,
      Angle_elem_position.bdr1, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_five, Array("L")),

    (Angle_elem_position.bur2, Angle_elem_position.ful2,
      Angle_elem_position.bdr3, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_six, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.ful3,
      Angle_elem_position.bdr2, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_six, Array("L'")),
    (Angle_elem_position.bur3, Angle_elem_position.ful3,
      Angle_elem_position.bdr2, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_six, Array("L2")),
    (Angle_elem_position.bur3, Angle_elem_position.ful2,
      Angle_elem_position.bdr3, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_six, Array("L")),

    (Angle_elem_position.bur1, Angle_elem_position.ful1,
      Angle_elem_position.bdr3, Angle_elem_position.fdl3, Side_position.left) -> (OppositeState.opp_seven, Array("")),
    (Angle_elem_position.bur2, Angle_elem_position.ful1,
      Angle_elem_position.bdr2, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_seven, Array("L'")),
    (Angle_elem_position.bur3, Angle_elem_position.ful3,
      Angle_elem_position.bdr1, Angle_elem_position.fdl1, Side_position.left) -> (OppositeState.opp_seven, Array("L2")),
    (Angle_elem_position.bur1, Angle_elem_position.ful2,
      Angle_elem_position.bdr1, Angle_elem_position.fdl2, Side_position.left) -> (OppositeState.opp_seven, Array("L")),

    // for front side
    (Angle_elem_position.ful1, Angle_elem_position.fur1,
      Angle_elem_position.fdl1, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_one, Array("")), // not used
    (Angle_elem_position.ful2, Angle_elem_position.fur2,
      Angle_elem_position.fdl3, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.ful2, Angle_elem_position.fur2,
      Angle_elem_position.fdl1, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_one, Array("F'")),
    (Angle_elem_position.ful1, Angle_elem_position.fur2,
      Angle_elem_position.fdl3, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_one, Array("F2")),
    (Angle_elem_position.ful2, Angle_elem_position.fur1,
      Angle_elem_position.fdl3, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_one, Array("F")),

    (Angle_elem_position.ful3, Angle_elem_position.fur3,
      Angle_elem_position.fdl2, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.ful3, Angle_elem_position.fur3,
      Angle_elem_position.fdl1, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_two, Array("F'")),
    (Angle_elem_position.ful1, Angle_elem_position.fur3,
      Angle_elem_position.fdl2, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_two, Array("F2")),
    (Angle_elem_position.ful3, Angle_elem_position.fur1,
      Angle_elem_position.fdl2, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_two, Array("F")),

    (Angle_elem_position.ful2, Angle_elem_position.fur1,
      Angle_elem_position.fdl1, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_three, Array("")),
    (Angle_elem_position.ful1, Angle_elem_position.fur2,
      Angle_elem_position.fdl3, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_three, Array("F'")),
    (Angle_elem_position.ful3, Angle_elem_position.fur1,
      Angle_elem_position.fdl1, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_three, Array("F2")),
    (Angle_elem_position.ful1, Angle_elem_position.fur3,
      Angle_elem_position.fdl2, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_three, Array("F")),

    (Angle_elem_position.ful2, Angle_elem_position.fur3,
      Angle_elem_position.fdl2, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_four, Array("")),
    (Angle_elem_position.ful3, Angle_elem_position.fur2,
      Angle_elem_position.fdl3, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_four, Array("F")),

    (Angle_elem_position.ful1, Angle_elem_position.fur3,
      Angle_elem_position.fdl1, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_five, Array("")),
    (Angle_elem_position.ful1, Angle_elem_position.fur1,
      Angle_elem_position.fdl3, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_five, Array("F'")),
    (Angle_elem_position.ful2, Angle_elem_position.fur1,
      Angle_elem_position.fdl2, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_five, Array("F2")),
    (Angle_elem_position.ful3, Angle_elem_position.fur2,
      Angle_elem_position.fdl1, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_five, Array("F")),

    (Angle_elem_position.ful2, Angle_elem_position.fur2,
      Angle_elem_position.fdl3, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_six, Array("")),
    (Angle_elem_position.ful2, Angle_elem_position.fur3,
      Angle_elem_position.fdl2, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_six, Array("F'")),
    (Angle_elem_position.ful3, Angle_elem_position.fur3,
      Angle_elem_position.fdl2, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_six, Array("F2")),
    (Angle_elem_position.ful3, Angle_elem_position.fur2,
      Angle_elem_position.fdl3, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_six, Array("F")),

    (Angle_elem_position.ful1, Angle_elem_position.fur1,
      Angle_elem_position.fdl3, Angle_elem_position.fdr3, Side_position.front) -> (OppositeState.opp_seven, Array("")),
    (Angle_elem_position.ful3, Angle_elem_position.fur1,
      Angle_elem_position.fdl3, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_seven, Array("F'")),
    (Angle_elem_position.ful2, Angle_elem_position.fur3,
      Angle_elem_position.fdl1, Angle_elem_position.fdr1, Side_position.front) -> (OppositeState.opp_seven, Array("F2")),
    (Angle_elem_position.ful1, Angle_elem_position.fur2,
      Angle_elem_position.fdl1, Angle_elem_position.fdr2, Side_position.front) -> (OppositeState.opp_seven, Array("F")),

    // for right side
    (Angle_elem_position.fur1, Angle_elem_position.bul1,
      Angle_elem_position.fdr1, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_one, Array("")), // not used
    (Angle_elem_position.fur2, Angle_elem_position.bul2,
      Angle_elem_position.fdr3, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.fur2, Angle_elem_position.bul2,
      Angle_elem_position.fdr1, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_one, Array("R'")),
    (Angle_elem_position.fur1, Angle_elem_position.bul2,
      Angle_elem_position.fdr3, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_one, Array("R2")),
    (Angle_elem_position.fur2, Angle_elem_position.bul1,
      Angle_elem_position.fdr3, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_one, Array("R")),

    (Angle_elem_position.fur3, Angle_elem_position.bul3,
      Angle_elem_position.fdr2, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_two, Array("")),
    (Angle_elem_position.fur3, Angle_elem_position.bul3,
      Angle_elem_position.fdr1, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_two, Array("R'")),
    (Angle_elem_position.fur1, Angle_elem_position.bul3,
      Angle_elem_position.fdr2, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_two, Array("R2")),
    (Angle_elem_position.fur3, Angle_elem_position.bul1,
      Angle_elem_position.fdr2, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_two, Array("R")),

    (Angle_elem_position.fur2, Angle_elem_position.bul1,
      Angle_elem_position.fdr1, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_three, Array("")),
    (Angle_elem_position.fur1, Angle_elem_position.bul2,
      Angle_elem_position.fdr2, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_three, Array("R'")),
    (Angle_elem_position.fur3, Angle_elem_position.bul1,
      Angle_elem_position.fdr1, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_three, Array("R2")),
    (Angle_elem_position.fur1, Angle_elem_position.bul3,
      Angle_elem_position.fdr3, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_three, Array("R")),

    (Angle_elem_position.fur2, Angle_elem_position.bul3,
      Angle_elem_position.fdr2, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_four, Array("")),
    (Angle_elem_position.fur3, Angle_elem_position.bul2,
      Angle_elem_position.fdr3, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_four, Array("R")),

    (Angle_elem_position.fur1, Angle_elem_position.bul3,
      Angle_elem_position.fdr1, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_five, Array("")),
    (Angle_elem_position.fur1, Angle_elem_position.bul1,
      Angle_elem_position.fdr3, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_five, Array("R'")),
    (Angle_elem_position.fur2, Angle_elem_position.bul1,
      Angle_elem_position.fdr2, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_five, Array("R2")),
    (Angle_elem_position.fur3, Angle_elem_position.bul2,
      Angle_elem_position.fdr1, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_five, Array("R")),

    (Angle_elem_position.fur3, Angle_elem_position.bul2,
      Angle_elem_position.fdr3, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_six, Array("")),
    (Angle_elem_position.fur3, Angle_elem_position.bul3,
      Angle_elem_position.fdr3, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_six, Array("R'")),
    (Angle_elem_position.fur2, Angle_elem_position.bul3,
      Angle_elem_position.fdr3, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_six, Array("R2")),
    (Angle_elem_position.fur2, Angle_elem_position.bul2,
      Angle_elem_position.fdr2, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_six, Array("R")),

    (Angle_elem_position.fur1, Angle_elem_position.bul1,
      Angle_elem_position.fdr2, Angle_elem_position.bdl3, Side_position.right) -> (OppositeState.opp_seven, Array("")),
    (Angle_elem_position.fur3, Angle_elem_position.bul1,
      Angle_elem_position.fdr3, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_seven, Array("R'")),
    (Angle_elem_position.fur2, Angle_elem_position.bul3,
      Angle_elem_position.fdr1, Angle_elem_position.bdl1, Side_position.right) -> (OppositeState.opp_seven, Array("R2")),
    (Angle_elem_position.fur1, Angle_elem_position.bul2,
      Angle_elem_position.fdr1, Angle_elem_position.bdl2, Side_position.right) -> (OppositeState.opp_seven, Array("R")),

    // for back side
    (Angle_elem_position.bul1, Angle_elem_position.bur1,
      Angle_elem_position.bdl1, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_one, Array("")), // not used
    (Angle_elem_position.bul2, Angle_elem_position.bur3,
      Angle_elem_position.bdl3, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.bul2, Angle_elem_position.bur3,
      Angle_elem_position.bdl1, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_one, Array("B'")),
    (Angle_elem_position.bul1, Angle_elem_position.bur3,
      Angle_elem_position.bdl3, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_one, Array("B2")),
    (Angle_elem_position.bul2, Angle_elem_position.bur1,
      Angle_elem_position.bdl3, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_one, Array("B")),

    (Angle_elem_position.bul3, Angle_elem_position.bur2,
      Angle_elem_position.bdl2, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_two, Array("")),
    (Angle_elem_position.bul3, Angle_elem_position.bur2,
      Angle_elem_position.bdl1, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_two, Array("B'")),
    (Angle_elem_position.bul1, Angle_elem_position.bur2,
      Angle_elem_position.bdl2, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_two, Array("B2")),
    (Angle_elem_position.bul3, Angle_elem_position.bur1,
      Angle_elem_position.bdl2, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_two, Array("B")),

    (Angle_elem_position.bul2, Angle_elem_position.bur1,
      Angle_elem_position.bdl1, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_three, Array("")),
    (Angle_elem_position.bul1, Angle_elem_position.bur3,
      Angle_elem_position.bdl2, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_three, Array("B'")),
    (Angle_elem_position.bul3, Angle_elem_position.bur1,
      Angle_elem_position.bdl1, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_three, Array("B2")),
    (Angle_elem_position.bul1, Angle_elem_position.bur2,
      Angle_elem_position.bdl3, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_three, Array("B")),

    (Angle_elem_position.bul2, Angle_elem_position.bur2,
      Angle_elem_position.bdl2, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_four, Array("")),
    (Angle_elem_position.bul3, Angle_elem_position.bur3,
      Angle_elem_position.bdl3, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_four, Array("B")),

    (Angle_elem_position.bul1, Angle_elem_position.bur2,
      Angle_elem_position.bdl1, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_five, Array("")),
    (Angle_elem_position.bul1, Angle_elem_position.bur1,
      Angle_elem_position.bdl3, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_five, Array("B'")),
    (Angle_elem_position.bul2, Angle_elem_position.bur1,
      Angle_elem_position.bdl2, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_five, Array("B2")),
    (Angle_elem_position.bul3, Angle_elem_position.bur3,
      Angle_elem_position.bdl1, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_five, Array("B")),

    (Angle_elem_position.bul3, Angle_elem_position.bur3,
      Angle_elem_position.bdl2, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_six, Array("")),
    (Angle_elem_position.bul3, Angle_elem_position.bur2,
      Angle_elem_position.bdl3, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_six, Array("B'")),
    (Angle_elem_position.bul2, Angle_elem_position.bur2,
      Angle_elem_position.bdl3, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_six, Array("B2")),
    (Angle_elem_position.bul2, Angle_elem_position.bur3,
      Angle_elem_position.bdl2, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_six, Array("B")),

    (Angle_elem_position.bul1, Angle_elem_position.bur1,
      Angle_elem_position.bdl2, Angle_elem_position.bdr2, Side_position.back) -> (OppositeState.opp_seven, Array("")),
    (Angle_elem_position.bul3, Angle_elem_position.bur1,
      Angle_elem_position.bdl3, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_seven, Array("B'")),
    (Angle_elem_position.bul2, Angle_elem_position.bur3,
      Angle_elem_position.bdl1, Angle_elem_position.bdr1, Side_position.back) -> (OppositeState.opp_seven, Array("B2")),
    (Angle_elem_position.bul1, Angle_elem_position.bur3,
      Angle_elem_position.bdl1, Angle_elem_position.bdr3, Side_position.back) -> (OppositeState.opp_seven, Array("B")),

    // for down side
    (Angle_elem_position.fdl1, Angle_elem_position.fdr1,
      Angle_elem_position.bdr1, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_one, Array("")), // not used
    (Angle_elem_position.fdl3, Angle_elem_position.fdr3,
      Angle_elem_position.bdr2, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_one, Array("")),
    (Angle_elem_position.fdl3, Angle_elem_position.fdr3,
      Angle_elem_position.bdr1, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_one, Array("D'")),
    (Angle_elem_position.fdl1, Angle_elem_position.fdr3,
      Angle_elem_position.bdr2, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_one, Array("D2")),
    (Angle_elem_position.fdl3, Angle_elem_position.fdr1,
      Angle_elem_position.bdr2, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_one, Array("D")),

    (Angle_elem_position.fdl2, Angle_elem_position.fdr2,
      Angle_elem_position.bdr3, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_two, Array("")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr2,
      Angle_elem_position.bdr1, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_two, Array("D'")),
    (Angle_elem_position.fdl1, Angle_elem_position.fdr2,
      Angle_elem_position.bdr3, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_two, Array("D2")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr1,
      Angle_elem_position.bdr3, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_two, Array("D")),

    (Angle_elem_position.fdl3, Angle_elem_position.fdr1,
      Angle_elem_position.bdr1, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_three, Array("")),
    (Angle_elem_position.fdl1, Angle_elem_position.fdr3,
      Angle_elem_position.bdr3, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_three, Array("D'")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr1,
      Angle_elem_position.bdr1, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_three, Array("D2")),
    (Angle_elem_position.fdl1, Angle_elem_position.fdr2,
      Angle_elem_position.bdr2, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_three, Array("D")),

    (Angle_elem_position.fdl3, Angle_elem_position.fdr2,
      Angle_elem_position.bdr3, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_four, Array("")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr3,
      Angle_elem_position.bdr2, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_four, Array("D")),

    (Angle_elem_position.fdl1, Angle_elem_position.fdr2,
      Angle_elem_position.bdr1, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_five, Array("")),
    (Angle_elem_position.fdl1, Angle_elem_position.fdr1,
      Angle_elem_position.bdr3, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_five, Array("D'")),
    (Angle_elem_position.fdl3, Angle_elem_position.fdr1,
      Angle_elem_position.bdr3, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_five, Array("D2")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr2,
      Angle_elem_position.bdr1, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_five, Array("D")),

    (Angle_elem_position.fdl3, Angle_elem_position.fdr2,
      Angle_elem_position.bdr3, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_six, Array("")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr2,
      Angle_elem_position.bdr2, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_six, Array("D'")),
    (Angle_elem_position.fdl3, Angle_elem_position.fdr2,
      Angle_elem_position.bdr3, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_six, Array("D2")),
    (Angle_elem_position.fdl3, Angle_elem_position.fdr3,
      Angle_elem_position.bdr3, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_six, Array("D")),

    (Angle_elem_position.fdl1, Angle_elem_position.fdr1,
      Angle_elem_position.bdr3, Angle_elem_position.bdl3, Side_position.down) -> (OppositeState.opp_seven, Array("")),
    (Angle_elem_position.fdl2, Angle_elem_position.fdr1,
      Angle_elem_position.bdr2, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_seven, Array("D'")),
    (Angle_elem_position.fdl3, Angle_elem_position.fdr2,
      Angle_elem_position.bdr1, Angle_elem_position.bdl1, Side_position.down) -> (OppositeState.opp_seven, Array("D2")),
    (Angle_elem_position.fdl1, Angle_elem_position.fdr3,
      Angle_elem_position.bdr1, Angle_elem_position.bdl2, Side_position.down) -> (OppositeState.opp_seven, Array("D")),

    /*

     */
  )
}
