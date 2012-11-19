BlXiti = {
  xitiTrackClick: function() {
    if (!window.xt_med) {
      return;
    }
    var zone = arguments[0];
    var label = arguments[1];

    switch (zone) {
      case 1:
        if (Drupal.settings.BlXitiArgsClick != undefined) {
          xt_med('F', Drupal.settings.BlXitiArgsClick['xtn2'], Drupal.settings.BlXitiArgsClick[label]);
        }
        break;

      case 2:
        if (Drupal.settings.BlXitiArgsClick != undefined) {
          xt_med('F', Drupal.settings.BlXitiArgsClick['xtn2'], Drupal.settings.BlXitiArgsClick[label]);
        }
        break;
    }
  },
  trackerSearchFilter: function(obj) {
    var checkboks = $(obj);
    var name_checkbox = checkboks.attr('name');
    var id_checkbox = checkboks.attr('id');
    if (name_checkbox.indexOf('type_lot_') != -1) {
      var xiti_click = 'clic_' + checkboks.attr('value');
      BlXiti.xitiTrackClick(2, xiti_click);
    }
    else if (id_checkbox.indexOf('-exposition') != -1) {
      BlXiti.xitiTrackClick(2, id_checkbox.split('-').pop());
    }
    else if (id_checkbox.indexOf('-square') != -1) {
      BlXiti.xitiTrackClick(2, id_checkbox.split('-').pop());
    }
    else if (id_checkbox.indexOf('-delivery') != -1) {
      BlXiti.xitiTrackClick(2, id_checkbox.split('-').pop());
    }
    else if (id_checkbox.indexOf('-extra') != -1) {
      BlXiti.xitiTrackClick(2, id_checkbox.split('-').pop());
    }
    else if (id_checkbox.indexOf('-floor') != -1) {
      BlXiti.xitiTrackClick(2, id_checkbox.split('-').pop());
    }
  }
}

Drupal.behaviors.BlXiti = {
  attach: function(context, settings) {
  }
}
