function showMsg(id){
	alert(id)
}

function formDisplay(form_id, disp){
	document.getElementById(form_id).style.display=disp
}

function revert(form_id){
	var form=document.getElementById(form_id)
	var cb=form.getElementsByTagName('INPUT')
	for(var i=0; i<cb.length; i++)
		if (cb[i].type=='checkbox' && cb[i].name=='itm')
			cb[i].checked = !cb[i].checked
}
						
function checked1n(form_id, warn){
	var form=document.getElementById(form_id)
	var inp=form.getElementsByTagName('INPUT')
	for(i=0; i<inp.length && (inp[i].type != 'checkbox' || !inp[i].checked); i++);
	if (i==inp.length && warn) alert(warn)
	return i<inp.length
}

function checked1(form_id, warn){
	var form=document.getElementById(form_id)
	var inp=form.getElementsByTagName('INPUT'), n=0
	for(i=0; i<inp.length; i++)
		if (inp[i].type == 'checkbox' && inp[i].checked)
			n++
	if (n==0 && warn) alert(warn)
	return n>0
}

function perform(form_id, action){
	var form = document.getElementById(form_id)
	var act = document.getElementById(form_id+'action')
	if (!act){
		act = document.createElement('INPUT')
		act.id = form_id+'action'
		act.name = 'action'
		act.type = 'hidden'
		form.appendChild(act)
	}
	if (act.value){
		alert('Please, do not click twice. The action is in progress')
		return
	}
	act.value = action
	form.method = 'post'
	form.submit()
}

function tgs(){ ;// Toggle /problem/ statistics
	var s = document.getElementById('stats').style
	var msg = document.getElementById('ssmsg')
	var m
	if (s.display=='none'){
		m = '&gt;';
		s.display = ''
	} else {
		m = '&lt;';
		s.display = 'none'
	}
	m = '&nbsp;'+m+'&nbsp;<BR>'
	var ar = new Array(10)
	for(p=0; p<10; p++) ar[p] = m
	msg.innerHTML = ar.join('')
}

function csf(){
	var e
	if ((e = document.getElementById('body')).value.length == 0){
		e.focus()
		alert('Please, add some text')
		return false
	}
	if ((e = document.getElementById('to')).value.length == 0){
		e.focus()
        return confirm('Do you really want to send a broadcast message?')
	}
	return true
}

function chgDisp(ID, hide){
	var a = document.getElementById(ID+'a').style, b = document.getElementById(ID+'b')
	var fc = b.firstChild
	b = b.style
	var i = b.display
	fc.style.visibility = (a.display=='none'?'hidden':'visible')
	b.display = a.display
	a.display = i
	if (!hide){
		if (fc.tagName == 'INPUT') fc.select()
		fc.focus()
		fc.focus() /* Opera 8.5 workaround */
		function hideIt(){
			chgDisp(ID, 1)
		}
		fc.onblur = hideIt
	}
	return false
}

function setTo(form_id,addr){
	var form=document.getElementById(form_id)
	var inp=form.getElementsByTagName('INPUT')
	var to = [], was = {}, curr
	for(i=0; i<inp.length; i++){
		if (!inp[i].checked) continue
		curr = ftc[inp[i].value][addr]
		if (was[curr]) continue
		was[to[to.length] = curr] = 1
	}
	document.getElementById('to').value = to.join(', ')
	document.getElementById('body').focus()
}

function w(event,t){
	if (!event.shiftKey) return
	var f = t.form, i
	var cb= f.getElementsByTagName('INPUT')
	for(i=cb.length-1; i>=0 && cb[i]!=t; i--);
	var p = cb[i--].checked
	for(; i>=0; i--){
		if (cb[i].type!='checkbox' || cb[i].name!='itm') continue
		if (cb[i].checked==p) break
		cb[i].checked = p
	}
}

function restoreSource(s){
	s.style.width = '100%'
}

function source_onLoad(){
	document.getElementById('problem').focus()
	var s = document.getElementById('source')
	s.rows = 2;
	s.cols = 40;
	s.onfocus = function (){
//		s.onfocus = 0
		s.value = ''
		s.style.width = '100%'
		s.rows = 40
	}
}