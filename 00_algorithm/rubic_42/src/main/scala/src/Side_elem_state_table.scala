/*
    Side elems state table

    Created for check crest and full state side of rubic.
    Example:
      if all elems position equal upElemStateTable_0 => this side full complete
      if all side elems equal upElemStateTable_0 => this side crest complete
      if all side elems equal upElemStateTable_1 => this side crest complete after one F movie
      if all side elems equal upElemStateTable_2 => this side crest complete after one F2 movie
 */

package src

trait Side_elem_state_table {
  val upElemStateTable_0 = Array(
    "a__0", "s__0", "a__1",
    "s__1", "c__0", "s__2",
    "a__2", "s__3", "a__3"
  )
  val upElemStateTable_1 = Array(
    "a__1", "s__2", "a__3",
    "s__0", "c__0", "s__3",
    "a__0", "s__1", "a__2"
  )
  val upElemStateTable_2 = Array(
    "a__3", "s__3", "a__2",
    "s__2", "c__0", "s__1",
    "a__1", "s__0", "a__0"
  )
  val upElemStateTable_3 = Array(
    "a__2", "s__1", "a__0",
    "s__3", "c__0", "s__0",
    "a__3", "s__2", "a__1"
  )
  val leftElemStateTable_0 = Array(
    "a__0", "s__1", "a__2",
    "s__4", "c__1", "s__5",
    "a__6", "s__8", "a__4"
  )
  val leftElemStateTable_1 = Array(
    "a__2", "s__5", "a__4",
    "s__1", "c__1", "s__8",
    "a__0", "s__4", "a__6"
  )
  val leftElemStateTable_2 = Array(
    "a__4", "s__8", "a__6",
    "s__5", "c__1", "s__4",
    "a__2", "s__1", "a__0"
  )
  val leftElemStateTable_3 = Array(
    "a__6", "s__4", "a__0",
    "s__8", "c__1", "s__1",
    "a__4", "s__5", "a__2"
  )
  val frontElemStateTable_0 = Array(
    "a__2", "s__3", "a__3",
    "s__5", "c__2", "s__6",
    "a__4", "s__9", "a__5"
  )
  val frontElemStateTable_1 = Array(
    "a__3", "s__6", "a__5",
    "s__3", "c__2", "s__9",
    "a__2", "s__5", "a__4"
  )
  val frontElemStateTable_2 = Array(
    "a__5", "s__9", "a__4",
    "s__6", "c__2", "s__5",
    "a__3", "s__3", "a__2"
  )
  val frontElemStateTable_3 = Array(
    "a__4", "s__5", "a__2",
    "s__9", "c__2", "s__3",
    "a__5", "s__6", "a__3"
  )
  val rightElemStateTable_0 = Array(
    "a__3", "s__2", "a__1",
    "s__6", "c__3", "s__7",
    "a__5", "s_10", "a__7"
  )
  val rightElemStateTable_1 = Array(
    "a__1", "s__7", "a__7",
    "s__2", "c__3", "s_10",
    "a__3", "s__6", "a__5"
  )
  val rightElemStateTable_2 = Array(
    "a__7", "s_10", "a__5",
    "s__7", "c__3", "s__6",
    "a__1", "s__2", "a__3"
  )
  val rightElemStateTable_3 = Array(
    "a__5", "s__6", "a__3",
    "s_10", "c__3", "s__2",
    "a__7", "s__7", "a__1"
  )
  val backElemStateTable_0 = Array(
    "a__1", "s__0", "a__0",
    "s__7", "c__4", "s__4",
    "a__7", "s_11", "a__6"
  )
  val backElemStateTable_1 = Array(
    "a__0", "s__4", "a__6",
    "s__0", "c__4", "s_11",
    "a__1", "s__7", "a__7"
  )
  val backElemStateTable_2 = Array(
    "a__6", "s_11", "a__7",
    "s__4", "c__4", "s__7",
    "a__0", "s__0", "a__1"
  )
  val backElemStateTable_3 = Array(
    "a__7", "s__7", "a__1",
    "s_11", "c__4", "s__0",
    "a__6", "s__4", "a__0"
  )
  val downElemStateTable_0 = Array(
    "a__4", "s__9", "a__5",
    "s__8", "c__5", "s_10",
    "a__6", "s_11", "a__7"
  )
  val downElemStateTable_1 = Array(
    "a__5", "s_10", "a__7",
    "s__9", "c__5", "s_11",
    "a__4", "s__8", "a__6"
  )
  val downElemStateTable_2 = Array(
    "a__7", "s_11", "a__6",
    "s_10", "c__5", "s__8",
    "a__5", "s__9", "a__4"
  )
  val downElemStateTable_3 = Array(
    "a__6", "s__8", "a__4",
    "s_11", "c__5", "s__9",
    "a__7", "s_10", "a__5"
  )
}
