function ruldown(ruler_num)
%RULDOWN Button down function for ruler lines.
 
%   Copyright 1988-2010 The MathWorks, Inc.

% ruler_num
%      1,2 button down on ruler line or marker
%      0 button down on some other line in the mainaxes, routed here
%        through pickfcn
%

    fig = gcf;
    if justzoom(fig), return, end
    ud = get(fig,'UserData');

    p = get(ud.mainaxes,'CurrentPoint');

    if ruler_num == 0
        % 3.5 is the "magic number" (used to be 6.5)
        mpos = get(ud.mainaxes,'Position');
        if ud.ruler.type(1)=='h'
            five_pix = 3.5*diff(get(ud.mainaxes,'YLim'))/mpos(4);
            ruler_num = 2 - (abs(p(1,2)-ud.ruler.value.y1)<=five_pix);
        else
            five_pix = 3.5*diff(get(ud.mainaxes,'XLim'))/mpos(3);
            ruler_num = 2 - (abs(p(1,1)-ud.ruler.value.x1)<=five_pix);
        end
    elseif strcmp(get(gcf,'Pointer'),'arrow')
        % not a hand - just return
        % This means that the user clicked on the ruler, but the
        % hand was not the cursor because the ruler motion code
        % has a narrow region which sometimes misses the true
        % buttondown region of the line.
        % disp('warning: line button down rejected')
        return
    end

    if ud.pointer == 2 % help mode
        sbhelp('rulerdown',num2str(ruler_num))
        return
    end

    save_wbmf = get(fig,'WindowButtonMotionFcn');

    setptr(fig,'closedhand')
    set(ud.ruler.lines(1),'UserData',0)

    set(fig,'WindowButtonMotionFcn',['sbswitch(''rulermo'',' ...
                    num2str(ruler_num) ')'])
    set(fig,'WindowButtonUpFcn',['sbuserdata = get(gcf,''UserData''); '...
           'set(sbuserdata.ruler.lines(1),''userdata'',1), clear sbuserdata'])

    waitfor(ud.ruler.lines(1),'userdata',1)
  
    % OK we're back from the drag
    setptr(fig,['hand' num2str(ruler_num)])
    set(fig,'WindowButtonMotionFcn',save_wbmf);
    set(fig,'WindowButtonUpFcn','');

