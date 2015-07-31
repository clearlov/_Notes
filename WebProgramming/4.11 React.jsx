/**
 * @see https://facebook.github.io/react/docs/tags-and-attributes.html
 */
/**
 * @warning distinguish the `this` is map
 * this.[state|prop].vars.map(function(item, i){}, hanle_this = each item);
 */
handle: function(){},
render: function(){
  var this_ = this;
  return (
    <div>{
      this.state.items.map(function(item, i){
        var bound_handle = this_.handle.bind(item, i);    // notice `this_`
        return (
          <a href="javascript:void(0)" onClick=bound_handle>Lef</a>
          <a href="javascript:void(0)" onClick=this_.handle>Well</a>
        );
      });
    }</div>
  );
}

render: function(){
  var list = this.props.items.map(function(item, i){
    var bound_handle = this.handle.bind(item, i);
    return (
      <a href="javascript:void(0)" onClick=bound_handle>Lef</a>
      <a href="javascript:void(0)" onClick=this.handle>Well</a>
    );
  }, this);     // assign interior `this` to outter `this`
  return (
    <div>{list}</div>
  );
}

/**
 * Class and Inline Styles handle
 * @see http://facebook.github.io/react/tips/inline-styles.html
 * @see http://facebook.github.io/react/docs/class-name-manipulation.html
 */
render: function(){
  var style = {
    color: '#f00',
    backgroundImage: 'url(lef_well.png)',
  };
  var cs = React.addons.classSet;
  var cls = cs({
    'p': true,
    'a': this.props.isA,
    'mg': this.props.needMarginBottom
  });
  var cls2 = cs('p', 'a', 'mg');  // class="p a mg"
  // <div class="p"> or <div class="p a"> or  <div class="p a mg"> ...
  return <div style={style} className={cls}></div>
}

/**
 * @see
 *  https://facebook.github.io/react/tips/expose-component-functions.html
 *  http://facebook.github.io/react/docs/events.html
 * Events:
 *  SyntheticEvent
 *  Clipboard Events: onCopy onCut onPaste
 *    DomDataTransfer clipboardData
 *  Keyboard Events:  onKeyDown onKeyPress onKeyUp
 *    boolean:  altKey ctrlKey metaKey repeat shiftKey
 *    Number:   charCode keyCode location which
 *    function: getModifierState(key)
 *    String:   key locale
 *  Focus Events: onFocus onBlur
 *    DOMEventTarget relatedTarget
 *  Form Events: onChange onInput onSubmit
 *  Mouse Events:
 *    onClick onContextMenu onDoubleClick onDrag onDragEnd onDragEnter onDragExit
 *    onDragLeave onDragOver onDragStart onDrop onMouseDown onMouseEnter onMouseLeave
 *    onMouseMove onMouseOut onMouseOver onMouseUp
 *      boolean altKey ctrlKey metaKey shiftKey
 *      Number button buttons clientX clientY pageX pageY screenX screenY
 *      function getModifierState(key)
 *      DOMEventTarget relatedTarget
 *  Touch Evnets: onTouchCancel onTouchEnd onTouchMove onTouchStart
 *  UI Events: onScrool
 *    Number detail
 *    DOMAbstractView view
 *  Wheel Events: onWheel
 *    Number: daltaMode deltaX deltaY deltaZ
 */
var Rcc = React.createClass({
  getInitialState: function(){},
  handleClick: function(e){
  
  },
  render: function(){
    return (
      <div>
        {
          this.state.items.map(function(item, i){
            var bound_click = this.handleClick.bind(this, i);
            return (
              <div onClick={bound_click}></div>
              <div onClick={this.handleClick}></div>
            ); 
          }, this)
        }
      </div>
    );
  }
});
