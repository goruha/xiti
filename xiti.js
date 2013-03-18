jQuery(function () {
  jQuery('#edit-xiti-tagging-plan').change(function() {
	  if(jQuery(this).is(':checked')) {
	      jQuery('#edit-xiti-default-xtn2').removeAttr('disabled');
	      jQuery('#edit-xiti-default-xtdi').removeAttr('disabled');
	    } 
	    else {
	      jQuery('#edit-xiti-default-xtn2').val('').attr('disabled', true);
	      jQuery('#edit-xiti-default-xtdi').val(0).attr('disabled', true);
	    }
  }).trigger('change');
});
