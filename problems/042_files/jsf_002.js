/*
 * JavaScript Filter
 *
 * Copyright Vladimir Sitnikov, 23-12-2005
 *           sitnikov2k@mail.ru
 *
 */

function gf(f, p){ return function(event){ return f(event, p) } }
function getDimensions(e){
	if (e.getBoundingClientRect){
		var r = e.getBoundingClientRect()
		var x = document.body.scrollTop-document.body.clientTop
		r.top+=x; r.bottom+=x
		x=document.body.scrollLeft-document.body.clientLeft
		r.left+=x; r.right+=x
		return r
	}
	var l=0, t=0
	var r={right:e.offsetWidth, bottom:e.offsetHeight}
	do{ l+=e.offsetLeft; t+=e.offsetTop } while(e=e.offsetParent)
	r.right+=(r.left=l); r.bottom+=(r.top=t)
	return r
}

function Jsf(f, data){
	var _this = this
	var d = document
	var dv, _v, z, si
	dv = d.createElement('<DIV>')
	dv.style.display='none'
	dv.className='jsf_div'
	d.body.appendChild(dv)

	function filter(){
		if (_v==f.value) return
	        _v=f.value
	        z=data.get(_v)
		var r = [], p=0, i=0
		r[p++] = '<table border=1>'
		r[p++]='<tr><td>'
		r[p++]=i<z.length?jsm.gv(z[i],1):'<font color=red>bad command or itemname</font>'
		for(i=1; i<z.length;i++){
			r[p++]='</td></tr><tr><td>'
			r[p++]=jsm.gv(z[i],1).split(_v).join('<b>'+_v+'</b>')
		}
		r[p++] = '</td></tr>'
		r[p++] = '</table>'
		dv.innerHTML=r.join('')
		si=-1
	}
	function keyUp(event){
		filter()
		return f.old_onkeyup?f.old_onkeyup(event):true
	}
	function keyPress(event){
		filter()
		return f.old_onkeypress?f.old_onkeypress(event):true
	}
	function blur(event){
		dv.style.display='none'
		return f.old_onblur?f.old_onblur(event):true
	}
	function keyDown(event){
		var v=f.value
		filter()
//		window.status='d: '+event.keyCode
		if (event.keyCode!=13){
			var dim = getDimensions(f)
			dv.style.top = dim.bottom
			dv.style.left = dim.left
			dv.style.display='block'
		}
		switch(event.keyCode){
		  case 38: case 40:
		  	chSelection((si+event.keyCode-39+z.length+2)%(z.length+1)-1)
			if (event.preventDefault) event.preventDefault()
			if (event.stopPropagation) event.stopPropagation()
			return false
		  case 33:
		  	chSelection(0)
			if (event.preventDefault) event.preventDefault()
			if (event.stopPropagation) event.stopPropagation()
			return false
		  case 34:
		  	chSelection(z.length-1)
			if (event.preventDefault) event.preventDefault()
			if (event.stopPropagation) event.stopPropagation()
			return false
		  case 13:
		  	if (si>=0){
				f.value=jsm.gv(z[si],0);
				dv.style.display='none';
				return false;
			}
			return true;
		  case 27:
				dv.style.display='none';
				return false;
		}
		return true
	}
	function chSelection(ni){
		var t = dv.children[0]
		if (si>=0)
			t.rows[si].className=''
		si=ni
		if (si>=0)
			t.rows[si].className='hl'
	}
	function save(n, p){ f['old_'+n] = f[n]; f[n]=null; f.attachEvent(n, p); }
	save('onkeydown', keyDown);
	save('onkeypress', keyPress);
	save('onkeyup', keyUp);
	save('onblur', blur);
	if (f.setAttribute) f.setAttribute('autocomplete', 'off')
}

function Jsm(){
	var _this = this
	this.gv = function(x,i){ return x instanceof Array?x[i]:x }
	this.flds = {}
	this.attach = function(fid, type, data){
		this.flds[fid] = {type:type, data:data}
	}
	var types ={
		array: function(arr){
		        var ul = arr.length
			var esc = new RegExp().compile('([\\[\\]\\\\(){}+$^.])','g')
			this.get = function(r){
			        var re = new RegExp(r.replace(esc,"\\$1").split('?').join('.').split('*').join('.*'),'i')
				var z = []
				for(var i=0; i<ul && z.length<15; i++)
					if (re.test(_this.gv(arr[i],1))) z[z.length] = arr[i]
				return z
			}
		}

	};
	window.attachEvent('onload', function(){
		for(var i in _this.flds){
			var f = _this.flds[i]
			var e = document.getElementById(i)
			if (!e) continue
			f.jsf = new Jsf(e, new (types[f.type])(f.data))
		}
	})
}

var jsm = new Jsm()
