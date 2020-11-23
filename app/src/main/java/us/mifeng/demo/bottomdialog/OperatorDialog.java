package us.mifeng.demo.bottomdialog;

import android.app.Activity;
import android.app.Dialog;
import android.view.View;
import android.widget.AdapterView;

import java.util.List;

import us.mifeng.demo.bean.OperatorVo;

public class OperatorDialog<T extends OperatorVo> implements AdapterView.OnItemClickListener {
    private Dialog dialog;
    private Activity mActivity;
    private List<T> operatorList;
    private OperatorListener listener;
    public OperatorDialog(Activity mActivity,List<T> operatorList,OperatorListener listener){
        this.mActivity=mActivity;
        this.operatorList=operatorList;
        this.listener=listener;
    }

    public void showDialog(int showType){
        
    }
    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

    }

    public interface  OperatorListener<Q extends OperatorVo>{
        void onSelectOp( Q  oper);
        void onCancel();
    }
}
