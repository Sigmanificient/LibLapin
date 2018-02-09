<div class="prototype">
  $Ktypedef struct@ $Ts_bunny_disconnected@<br />
  {<br />
  $A $Tt_bunny_comptype@ $Scomtype@;<br />
  $A $Tunsigned int@ $Stime@;<br />
  $A $Tt_bunny_comerror@ $Serrortype@;<br />
  $A $Tint@ $Sfd@;<br />
  <br />
  } $Tt_bunny_disconnected@;<br />
</div>
<hr />

<div class="resume">
  <h3>Description</h3>
  $A This structure is used by t_bunny_communication if its t_bunny_comtype
  is $SNETDISCONNECTED@. It indicates a connection was lost.
</div>
<hr />

<div class="parameters">
  <h3>Attributes</h3>
  <ul>
    <li>
      $Tt_bunny_comtype@ $Scomtype@:<br />
      $A Should contain $SNETDISCONNECTED@ if this is effectively a t_bunny_disconnected.
    </li>
    <li>
      $Tunsigned int@ $Stime@:<br />
      $A Time that was not consumed by the scheduling operation returning
      the t_bunny_communication.
    </li>
    <li>
      $Tint@ $Sfd@:<br />
      $A The file descriptor of the now lost connection. It is an invalid
      file descriptor, as it is expired.
    </li>
  </ul>
</div>

<div class="related_functions">
  <h3>Related functions</h3>
  <ul>
    <li>t_bunny_communication</li>
    <li>t_bunny_comtype</li>
  </ul>
</div>
