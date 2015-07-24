/**
 * class hanle
 */
render: function(){
  var cs = React.addons.classSet;
  var cls = cs({
    'p': true,
    'a': this.props.isA,
    'mg': this.props.needMarginBottom
  });
  // <div class="p"> or <div class="p a"> or  <div class="p a mg"> ...
  return <div className={cls}></div>
}
